
#include<string>
#include<iostream>
#include<vector>
using namespace std;
//以Money的类别作为内部标识，面值作为外部状态。
enum MoneyCategory   //类别，内在标识，作为标识码
{
	Coin,
	bankNote
};

enum FaceValue      //面值，外部标识，需要存储的对象
{
	ValueOne = 1,
	ValueTwo
};

class Money      //抽象父类
{
public:
	Money(MoneyCategory cate) :m_mCate(cate){}
	virtual ~Money(){ cout << "~Money() " << endl; }
	virtual void save() = 0;
private:
	MoneyCategory m_mCate;
};

class MoneyCoin :public Money    //具体子类1
{
public:
	MoneyCoin(MoneyCategory cate) :Money(cate){}
	~MoneyCoin(){ cout << "~MoneyCoin()" << endl; }
	void save()
	{
		cout << "Save Coin" << endl;
	}
};

class MoneyNote :public Money   //具体子类2
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
		switch (cate)    //以类别作为标识码
		{
		case Coin:
		{
			if (m_coin == nullptr)  //内存中存在标识码所标识的对象，则直接调用，不再创建
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