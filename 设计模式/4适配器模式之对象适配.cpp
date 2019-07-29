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

//对象适配器相比类适配器来说更加灵活，他可以选择性适配自己想适配的对象。例如我们下面把代码改成这样，你也许就会明白为什么我这样说：
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
		cout << "三相插头转为两厢插头！" << endl;
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