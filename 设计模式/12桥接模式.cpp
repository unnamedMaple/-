
#include<string>
#include<iostream>
#include<vector>
using namespace std;
//������App�������ֻ�ȫ�������ֿ���ʹ����������Ž�
class App
{
public:
	virtual ~App(){ cout << "~App()" << endl; }
	virtual void run() = 0;
};

class GameApp :public App
{
public:
	void run()
	{
		cout << "GameApp Running" << endl;
	}
};

class TranslateApp :public App
{
public:
	void run()
	{
		cout << "TranslateApp Running" << endl;
	}
};

class MobilePhone
{
public:
	virtual ~MobilePhone(){ cout << "~MobilePhone()" << endl; }
	virtual void appRun(App* app) = 0;  //ʵ��App���ֻ����Ž�
};

class XiaoMi :public MobilePhone
{
public:
	void appRun(App* app)
	{
		cout << "XiaoMi: ";
		app->run();
	}
};

class HuaWei :public MobilePhone
{
public:
	void appRun(App* app)
	{
		cout << "HuaWei: ";
		app->run();
	}
};


int main()
{
	App* gameApp = new GameApp;
	App* translateApp = new TranslateApp;
	MobilePhone* mi = new XiaoMi;
	MobilePhone* hua = new HuaWei;
	mi->appRun(gameApp);
	mi->appRun(translateApp);
	hua->appRun(gameApp);
	hua->appRun(translateApp);
	delete hua;
	delete mi;
	delete gameApp;
	delete translateApp;

	return 0;
}