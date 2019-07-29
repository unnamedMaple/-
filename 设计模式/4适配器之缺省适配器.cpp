#include "iostream"
using namespace std;


class Target {
public:
	virtual void f1(){};
	virtual void f2(){};
	virtual void f3(){};
};
class DefaultAdapter : public Target
{
public:
	void f1() {
	}
	void f2() {
	}
	void f3() {
	}
};
class MyInteresting :public DefaultAdapter
{
public:
	void f3(){
		cout << "呵呵，我就对f3()方法感兴趣，别的不管了！" << endl;
	}
};


int main()
{
	// Create adapter and place a request
	Target *t = new MyInteresting();
	t->f3();

	return 0;
}