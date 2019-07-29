#include "iostream"
using namespace std;


//������������ͷ
class ThreePhaseOutlet
{
public:
	void doThreePhasePlugin()
	{
		cout << "�����ͷǿ�Ʋ��룡" << endl;
	}
};

//��������Ҫ�������ͷ
class TwoPhaseOutlet
{
public:
	virtual void doPlugin() = 0;
};

//�����������������������˵������������ѡ���������Լ�������Ķ���������������Ѵ���ĳ���������Ҳ��ͻ�����Ϊʲô������˵��
class OutletConvertor : public TwoPhaseOutlet
{
public:
	OutletConvertor()
	{
		m_out = new ThreePhaseOutlet;
	}
	void doPlugin()
	{
		doConvertor();
		m_out->doThreePhasePlugin();
	}
	void doConvertor()
	{
		cout << "�����ͷתΪ�����ͷ��" << endl;
	}

public:
	ThreePhaseOutlet *m_out;
};


int main()
{
	TwoPhaseOutlet *outlet = new OutletConvertor();
	outlet->doPlugin();

	return 0;
}