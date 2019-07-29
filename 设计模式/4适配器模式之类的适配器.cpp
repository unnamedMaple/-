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

//Ȼ���㽫��Ҫ�ҵ�һ��ת��ͷ���������ͷת��Ϊ�������ͷ
class OutletConvertor : public TwoPhaseOutlet, public ThreePhaseOutlet
{
public:
	void doPlugin()
	{
		doConvertor();
		doThreePhasePlugin();
	}
	void doConvertor()
	{
		cout << "�����ͷתΪ�����ͷ��" << endl;
	}
};


int main()
{
	TwoPhaseOutlet* outlet = new OutletConvertor();
	outlet->doPlugin();

	return 0;
}