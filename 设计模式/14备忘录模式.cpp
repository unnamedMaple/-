#include<string>
#include<iostream>
#include<vector>
using namespace std;
typedef struct  //��Ҫ�������Ϣ
{
	int grade;
	string arm;
	string corps;
}GameValue;

class Memento   //����¼��
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

class Game     //�ͻ��� ��Ϸ
{
public:
	Game(GameValue value) :m_gameValue(value)
	{}
	void addGrade()  //�ȼ�����
	{
		m_gameValue.grade++;
	}
	void replaceArm(string arm)  //��������
	{
		m_gameValue.arm = arm;
	}
	void replaceCorps(string corps)  //��������
	{
		m_gameValue.corps = corps;
	}
	Memento saveValue()    //���浱ǰ��Ϣ
	{
		Memento memento(m_gameValue);
		return memento;
	}
	void load(Memento memento) //������Ϣ
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

class Caretake //����¼������
{
public:
	void save(Memento memento)  //������Ϣ
	{
		m_memento = memento;
	}
	Memento load()            //���ѱ������Ϣ
	{
		return m_memento;
	}
private:
	Memento m_memento;
};


int main()
{
	GameValue v1 = { 0, "Ak", "3K" };
	Game game(v1);    //��ʼֵ
	game.addGrade();
	game.showValue();
	cout << "----------" << endl;
	Caretake care;
	care.save(game.saveValue());  //���浱ǰֵ
	game.addGrade();          //�޸ĵ�ǰֵ
	game.replaceArm("M16");
	game.replaceCorps("123");
	game.showValue();
	cout << "----------" << endl;
	game.load(care.load());   //�ָ���ʼֵ
	game.showValue();

	return 0;
}