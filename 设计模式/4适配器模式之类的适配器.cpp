#include "iostream"
using namespace std;


//这是你的三相插头
class ThreePhaseOutlet
{
public:
	void doThreePhasePlugin()
	{
		cout << "三相插头强势插入！" << endl;
	}
};

//这是你想要的两相插头
class TwoPhaseOutlet
{
public:
	virtual void doPlugin() = 0;
};

//然后你将需要找到一个转接头，将三相插头转换为“两相插头
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
		cout << "三相插头转为两厢插头！" << endl;
	}
};


int main()
{
	TwoPhaseOutlet* outlet = new OutletConvertor();
	outlet->doPlugin();

	return 0;
}