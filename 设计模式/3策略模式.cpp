#include<iostream>

using namespace std;

class Strategy{
public:
	virtual void Algorithm() = 0;
};


class StrategyA :public Strategy{
	void Algorithm(){
		cout << "StrategyA" << endl;
	}
};

class StrategyB :public Strategy{
	void Algorithm(){
		cout << "StrategyB" << endl;
	}
};

class Context{
private:
	Strategy *strategy;
public:
	Context(Strategy *strategy){
		this->strategy = strategy;
	}
	void ContextAlgorithm(){
		this->strategy->Algorithm();
	}
};

int main()
{
	Context *context;
	context = new Context(new StrategyA());
	context->ContextAlgorithm();

	context = new Context(new StrategyB());
	context->ContextAlgorithm();
	return 0;
}
