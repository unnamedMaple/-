#include<string>
#include<iostream>
using namespace std;
class Clone
{
public :
	Clone()
	{

	}
	virtual ~Clone()
	{

	}
	virtual Clone* clone() = 0;
	virtual void show() = 0;
};

class Sheep :public Clone
{
public :
	Sheep(int id, string name) :Clone(), m_id(id), m_name(name)
	{
		
	}
	~Sheep()
	{

	}

	Sheep(const Sheep&obj)
	{
		this->m_id = obj.m_id;
		this->m_name = obj.m_name;
	}
	Clone* clone()
	{
		return new Sheep(*this);
	}
	void show()
	{
		cout << m_id << m_name;
	}

private :
	int m_id;
	string m_name;
};