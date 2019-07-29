#include<iostream>
using namespace std;
//ºìÉÕÈâ
class product1{
public:
	virtual void show() = 0;
};


//ÂéÆÅ¶¹¸¯

class product2{
public:
	virtual void show() = 0;
};


//ÔÁ²Ë¿ÚÎ¶µÄºìÉÕÈâ
class A1 :public product1{
public:
	void show(){
		cout << "ÔÁ²Ë¿ÚÎ¶µÄºìÉÕÈâ" << endl;
	}
};

//ÔÁ²Ë¿ÚÎ¶µÄÂéÆÅ¶¹¸¯
class A2 :public product2{
public:
	void show(){
		cout << "ÔÁ²Ë¿ÚÎ¶µÄÂéÆÅ¶¹¸¯" << endl;
	}
};


//´¨²Ë¿ÚÎ¶µÄºìÉÕÈâ
class B1 :public product1{
public:
	void show(){
		cout << "´¨²Ë¿ÚÎ¶µÄºìÉÕÈâ" << endl;
	}
};
//´¨²Ë¿ÚÎ¶µÄÂéÆÅ¶¹¸¯
class B2 :public product2{
public:
	void show(){
		cout << "´¨²Ë¿ÚÎ¶µÄÂéÆÅ¶¹¸¯" << endl;
	}
};




//³éÏó·¹¹İ
class Factory{
public:
	virtual product1* createProduct1() = 0;
	virtual product2* createProduct2() = 0;
};


//ÔÁ²Ë·¹¹İ
class FactoryA:public Factory{
public:
	product1* createProduct1(){
		return new A1();
	}
	product2* createProdcut2(){
		return new A2();
	}

};

//´¨Î¶·¹¹İ
class FactoryB :public Factory{
public:
	product1* createProduct1(){
		return new B1();
	}
	product2* createProdcut2(){
		return new B2();
	}
};
