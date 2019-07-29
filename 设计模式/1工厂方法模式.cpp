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
	//һ����������һ�ֲ�Ʒ������˼򵥹������޸Ĳ��ܹرյ����⡣ϵͳ������Ʒ������һ����Ʒ�������ɣ��Գ��󹤳�����Ӱ�졣
	//ȱ�㣺���ڴ�����ͬϵ�еĲ�Ʒ����Ϊ��
	product *pA = myFA.createProduct();
	product *pB = myFB.createProduct();
	return 0;

}