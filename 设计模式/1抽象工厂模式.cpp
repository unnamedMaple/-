#include<iostream>
using namespace std;
//������
class product1{
public:
	virtual void show() = 0;
};


//���Ŷ���

class product2{
public:
	virtual void show() = 0;
};


//���˿�ζ�ĺ�����
class A1 :public product1{
public:
	void show(){
		cout << "���˿�ζ�ĺ�����" << endl;
	}
};

//���˿�ζ�����Ŷ���
class A2 :public product2{
public:
	void show(){
		cout << "���˿�ζ�����Ŷ���" << endl;
	}
};


//���˿�ζ�ĺ�����
class B1 :public product1{
public:
	void show(){
		cout << "���˿�ζ�ĺ�����" << endl;
	}
};
//���˿�ζ�����Ŷ���
class B2 :public product2{
public:
	void show(){
		cout << "���˿�ζ�����Ŷ���" << endl;
	}
};




//���󷹹�
class Factory{
public:
	virtual product1* createProduct1() = 0;
	virtual product2* createProduct2() = 0;
};


//���˷���
class FactoryA:public Factory{
public:
	product1* createProduct1(){
		return new A1();
	}
	product2* createProdcut2(){
		return new A2();
	}

};

//��ζ����
class FactoryB :public Factory{
public:
	product1* createProduct1(){
		return new B1();
	}
	product2* createProdcut2(){
		return new B2();
	}
};
