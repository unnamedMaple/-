
#include<string>
#include<iostream>
#include<vector>
using namespace std;
//��Money�������Ϊ�ڲ���ʶ����ֵ��Ϊ�ⲿ״̬��
enum MoneyCategory   //������ڱ�ʶ����Ϊ��ʶ��
{
	Coin,
	bankNote
};

enum FaceValue      //��ֵ���ⲿ��ʶ����Ҫ�洢�Ķ���
{
	ValueOne = 1,
	ValueTwo
};

class Money      //������
{
public:
	Money(MoneyCategory cate) :m_mCate(cate){}
	virtual ~Money(){ cout << "~Money() " << endl; }
	virtual void save() = 0;
private:
	MoneyCategory m_mCate;
};

class MoneyCoin :public Money    //��������1
{
public:
	MoneyCoin(MoneyCategory cate) :Money(cate){}
	~MoneyCoin(){ cout << "~MoneyCoin()" << endl; }
	void save()
	{
		cout << "Save Coin" << endl;
	}
};

class MoneyNote :public Money   //��������2
{
public:
	MoneyNote(MoneyCategory cate) :Money(cate){}
	~MoneyNote(){ cout << "~MoneyNote()" << endl; }
	void save()
	{
		cout << "Save BankNote" << endl;
	}
};

class Bank
{
public:
	Bank() :m_coin(nullptr), m_note(nullptr), m_count(0){}
	~Bank()
	{
		if (m_coin != nullptr)
		{
			delete m_coin;
			m_coin = nullptr;
		}
		if (m_note != nullptr)
		{
			delete m_note;
			m_note = nullptr;
		}
	}
	void saveMoney(MoneyCategory cate, FaceValue value)
	{
		switch (cate)    //�������Ϊ��ʶ��
		{
		case Coin:
		{
			if (m_coin == nullptr)  //�ڴ��д��ڱ�ʶ������ʶ�Ķ�����ֱ�ӵ��ã����ٴ���
			{
				m_coin = new MoneyCoin(Coin);
			}
			m_coin->save();
			m_vector.push_back(value);
			break;
		}
		case bankNote:
		{
			if (m_note == nullptr)
			{
				m_note = new MoneyNote(bankNote);
			}
			m_note->save();
			m_vector.push_back(value);
			break;
		}
		default:
			break;
		}
	}

	int sumSave()
	{
		auto iter = m_vector.begin();
		for (; iter != m_vector.end(); iter++)
		{
			m_count += *iter;
		}
		return m_count;
	}

private:
	vector<FaceValue> m_vector;
	Money* m_coin;
	Money* m_note;
	int m_count;
};

int main()
{
	Bank b1;
	b1.saveMoney(Coin, ValueOne);
	b1.saveMoney(Coin, ValueTwo);
	b1.saveMoney(Coin, ValueTwo);
	b1.saveMoney(bankNote, ValueOne);
	b1.saveMoney(bankNote, ValueTwo);
	cout << b1.sumSave() << endl;

	return 0;
}