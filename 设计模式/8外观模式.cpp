#include<iostream>
using namespace std;
class Cpu
{
public:
	void productCpu()
	{
		cout << "Product Cpu" << endl;
	}
};

class Ram
{
public:
	void productRam()
	{
		cout << "Product Ram" << endl;
	}
};

class Graphics
{
public:
	void productGraphics()
	{
		cout << "Product Graphics" << endl;
	}
};

class Computer
{
public:
	void productComputer()
	{
		Cpu cpu;
		cpu.productCpu();
		Ram ram;
		ram.productRam();
		Graphics graphics;
		graphics.productGraphics();
	}
};


int main()
{
	//�ͻ�ֱ�ӵ���computer����������������ľ��岿�����������̡�Ҳ��ֱ�ӵ�����������
	Computer computer;
	computer.productComputer();

	Cpu cpu;
	cpu.productCpu();

	return 0;
}