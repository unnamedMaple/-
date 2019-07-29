

#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Dumplings    //������   ����
{
public:
	virtual ~Dumplings(){}
	virtual void showDressing() = 0;
};

class MeatDumplings :public Dumplings    //��ʵ��  ���ڽ���
{
public:
	~MeatDumplings(){ cout << "~MeatDumplings()" << endl; }
	void showDressing()
	{
		cout << "Add Meat" << endl;
	}
};

class DecoratorDumpling :public Dumplings    //װ����
{
public:
	DecoratorDumpling(Dumplings* d) :m_dumpling(d){}
	virtual ~DecoratorDumpling(){ cout << "~DecoratorDumpling()" << endl; }
	void showDressing()
	{
		m_dumpling->showDressing();
	}
private:
	Dumplings* m_dumpling;
};

class SaltDecorator :public DecoratorDumpling   // װ����  ����
{
public:
	SaltDecorator(Dumplings* d) :DecoratorDumpling(d){}
	~SaltDecorator(){ cout << "~SaltDecorator()" << endl; }
	void showDressing()
	{
		DecoratorDumpling::showDressing();   //ע���
		addDressing();
	}

private:
	void addDressing()
	{
		cout << "Add Salt" << endl;
	}
};

class OilDecorator :public DecoratorDumpling   //װ����  ����
{
public:
	OilDecorator(Dumplings* d) :DecoratorDumpling(d){}
	~OilDecorator(){ cout << "~OilDecorator()" << endl; }
	void showDressing()
	{
		DecoratorDumpling::showDressing(); //ע���
		addDressing();
	}

private:
	void addDressing()
	{
		cout << "Add Oil" << endl;
	}
};

class CabbageDecorator :public DecoratorDumpling  //װ����   ���߲�
{
public:
	CabbageDecorator(Dumplings* d) :DecoratorDumpling(d){}
	~CabbageDecorator(){ cout << "~CabbageDecorator()" << endl; }
	void showDressing()
	{
		DecoratorDumpling::showDressing(); //ע���
		addDressing();
	}

private:
	void addDressing()
	{
		cout << "Add Cabbage" << endl;
	}
};


int main()
{
	Dumplings* d = new MeatDumplings;       //ԭʼ�������
	Dumplings* d1 = new SaltDecorator(d);   //���κ�Ľ���
	Dumplings* d2 = new OilDecorator(d1);   //���ͺ�Ľ���
	Dumplings* d3 = new CabbageDecorator(d2);  //���߲˺�Ľ���
	d3->showDressing();
	delete d;
	delete d1;
	delete d2;
	delete d3;

	return 0;
}