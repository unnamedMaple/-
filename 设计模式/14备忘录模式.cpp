#include<string>
#include<iostream>
#include<vector>
using namespace std;
typedef struct  //需要保存的信息
{
	int grade;
	string arm;
	string corps;
}GameValue;

class Memento   //备忘录类
{
public:
	Memento(){}
	Memento(GameValue value) :m_gameValue(value){}
	GameValue getValue()
	{
		return m_gameValue;
	}
private:
	GameValue m_gameValue;
};

class Game     //客户类 游戏
{
public:
	Game(GameValue value) :m_gameValue(value)
	{}
	void addGrade()  //等级增加
	{
		m_gameValue.grade++;
	}
	void replaceArm(string arm)  //更换武器
	{
		m_gameValue.arm = arm;
	}
	void replaceCorps(string corps)  //更换工会
	{
		m_gameValue.corps = corps;
	}
	Memento saveValue()    //保存当前信息
	{
		Memento memento(m_gameValue);
		return memento;
	}
	void load(Memento memento) //载入信息
	{
		m_gameValue = memento.getValue();
	}
	void showValue()
	{
		cout << "Grade: " << m_gameValue.grade << endl;
		cout << "Arm  : " << m_gameValue.arm.data() << endl;
		cout << "Corps: " << m_gameValue.corps.data() << endl;
	}
private:
	GameValue m_gameValue;
};

class Caretake //备忘录管理类
{
public:
	void save(Memento memento)  //保存信息
	{
		m_memento = memento;
	}
	Memento load()            //读已保存的信息
	{
		return m_memento;
	}
private:
	Memento m_memento;
};


int main()
{
	GameValue v1 = { 0, "Ak", "3K" };
	Game game(v1);    //初始值
	game.addGrade();
	game.showValue();
	cout << "----------" << endl;
	Caretake care;
	care.save(game.saveValue());  //保存当前值
	game.addGrade();          //修改当前值
	game.replaceArm("M16");
	game.replaceCorps("123");
	game.showValue();
	cout << "----------" << endl;
	game.load(care.load());   //恢复初始值
	game.showValue();

	return 0;
}