#include<string>
#include<iostream>
using namespace std;
enum RequestLevel
{
	One = 1,
	Two,
	Three
};

class Leader
{
public:
	Leader(Leader* leader) :m_leader(leader){}
	virtual ~Leader(){}
	virtual void handleRequest(RequestLevel level) = 0;
protected:
	Leader* m_leader;
};

class Monitor :public Leader   //����1
{
public:
	Monitor(Leader* leader) :Leader(leader){}
	void handleRequest(RequestLevel level)
	{
		if (level < Two)
		{
			cout << "Mointor handle request : " << level << endl;
		}
		else
		{
			m_leader->handleRequest(level);
		}
	}
};

class Captain :public Leader    //����2
{
public:
	Captain(Leader* leader) :Leader(leader){}
	void handleRequest(RequestLevel level)
	{
		if (level < Three)
		{
			cout << "Captain handle request : " << level << endl;
		}
		else
		{
			m_leader->handleRequest(level);
		}
	}
};

class General :public Leader   //����3
{
public:
	General(Leader* leader) :Leader(leader){}
	void handleRequest(RequestLevel level)
	{
		cout << "General handle request : " << level << endl;
	}
};

int main()
{
	Leader* general = new General(nullptr);
	Leader* captain = new Captain(general);
	Leader* monitor = new Monitor(captain);
	monitor->handleRequest(Two);
	return 0;
}