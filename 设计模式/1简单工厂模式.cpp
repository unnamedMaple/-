#include<iostream>
using namespace std;

typedef enum{
	PA = 1,
	PB = 2
}ProductType;

class product{
public:
	virtual void print()  = 0;
};

class A:public product{
public :void print(){
		cout << "A" << endl;
	}
};

class B:public product{
public:
	void print(){
		cout << "B" << endl;
	}
};


class ProductFactory{
public :
	product* createProduct(ProductType type){
		switch (type)
		{

		case 1:
			return new A();
			break;
		case 2:
			return new B();
			break;
		default:
			return nullptr;
			break;
		}
	}
};


int main()
{

	//一个工厂生产所有产品,缺点对修改不封闭，每增加产品要修改工厂
	ProductFactory myFac;
	product *myA = myFac.createProduct(PA);
	myA->print();
	product *myB= myFac.createProduct(PB);
	myB->print();
	return 0;
}
