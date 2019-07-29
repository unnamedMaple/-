#include "iostream"
#include "list"
//#include <future>
using namespace std;


//����ģ��ΪĿ���࣬��ͼΪ�۲����ࡣ������ģ�ͷ����ı�ʱ��֪ͨ��ͼ�����
class View;

class DataModel   //Ŀ�������   ����ģ��
{
public:
	virtual ~DataModel(){}
	virtual void add(View* view) = 0;
	virtual void remove(View* view) = 0;
	virtual void notify() = 0;   //֪ͨ����
};

class View      //�۲��߳�����   ��ͼ
{
public:
	virtual ~View(){ cout << "~View()" << endl; }
	virtual void update() = 0;
};

class IntModel :public DataModel   //�����Ŀ���࣬ ����ģ��
{
public:
	~IntModel()
	{
		clear();
	}
	void add(View* view)
	{
		auto iter = std::find(m_list.begin(), m_list.end(), view); //�ж��Ƿ��ظ����
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
				delete *iter;        //�ͷ��ڴ�
				m_list.erase(iter);  //ɾ��Ԫ��
				break;
			}
		}
	}
	void notify()  //֪ͨ�۲��߸���
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
			for (; iter != m_list.end(); iter++)  //�ͷ��ڴ�
			{
				delete *iter;
			}
		}
	}
private:
	list<View*> m_list;
};

class TreeView :public View  //����Ĺ۲�����   ��ͼ
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