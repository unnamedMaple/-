#include "iostream"
#include "list"
//#include <future>
using namespace std;


//数据模型为目标类，视图为观察者类。当数据模型发生改变时，通知视图类更新
class View;

class DataModel   //目标抽象类   数据模型
{
public:
	virtual ~DataModel(){}
	virtual void add(View* view) = 0;
	virtual void remove(View* view) = 0;
	virtual void notify() = 0;   //通知函数
};

class View      //观察者抽象类   视图
{
public:
	virtual ~View(){ cout << "~View()" << endl; }
	virtual void update() = 0;
};

class IntModel :public DataModel   //具体的目标类， 整数模型
{
public:
	~IntModel()
	{
		clear();
	}
	void add(View* view)
	{
		auto iter = std::find(m_list.begin(), m_list.end(), view); //判断是否重复添加
		if (iter == m_list.end())
		{
			m_list.push_back(view);
		}
	}
	void remove(View* view)
	{
		auto iter = m_list.begin();
		for (; iter != m_list.end(); iter++)
		{
			if (*iter == view)
			{
				delete *iter;        //释放内存
				m_list.erase(iter);  //删除元素
				break;
			}
		}
	}
	void notify()  //通知观察者更新
	{
		auto iter = m_list.begin();
		for (; iter != m_list.end(); iter++)
		{
			(*iter)->update();
		}
	}
private:
	void clear()
	{
		if (!m_list.empty())
		{
			auto iter = m_list.begin();
			for (; iter != m_list.end(); iter++)  //释放内存
			{
				delete *iter;
			}
		}
	}
private:
	list<View*> m_list;
};

class TreeView :public View  //具体的观察者类   视图
{
public:
	TreeView(string name) :m_name(name), View(){}
	~TreeView(){ cout << "~TreeView()" << endl; }
	void update()
	{
		cout << m_name.data() << " : Update" << endl;
	}
private:
	string m_name;
};

int main()
{
	View* v1 = new TreeView("view1");
	View* v2 = new TreeView("view2");
	View* v3 = new TreeView("view3");
	View* v4 = new TreeView("view4");
	DataModel* model = new IntModel;
	model->add(v1);
	model->add(v2);
	model->add(v3);
	model->add(v2);
	model->add(v4);
	model->notify();
	cout << "----------" << endl;
	model->remove(v2);
	model->notify();
	delete model;
	while (1);
	return 0;
}