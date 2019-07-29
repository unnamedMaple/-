#include<iostream>
using namespace std;
	
class product{
public:
	virtual void print() = 0;
};

class A :public product{
public:void print(){
	cout << "A" << endl;
}
};

class B :public product{
public:
	void print(){
		cout << "B" << endl;
	}
};

class Factory{
public:
	virtual product* createProduct() = 0;
};

class FactoryA :public Factory{
public:
	product* createProduct(){
		return new A();
	}
};

class FactoryB :public Factory{
public:
	product* createProduct(){
		return new B();
	}
};


int main(){

	FactoryA myFA;
	FactoryB myFB;
	//一个工厂生产一种产品，解决了简单工厂的修改不能关闭的问题。系统新增产品，新增一个产品工厂即可，对抽象工厂不受影响。
	//缺点：对于创建不同系列的产品无能为力
	product *pA = myFA.createProduct();
	product *pB = myFB.createProduct();
	return 0;

}