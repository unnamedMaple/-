/*

单例模式：保证一个类仅有一个实例，并提供一个访问它的全局访问点。
    主要解决：一个全局使用的类频繁地创建与销毁。
	    何时使用：想控制实例数目，节省系统资源的时候。
		    如何解决：判断系统是否已存在单例，如果有则返回，没有则创建。
			    关键代码：构造函数是私有的。
				
懒汉：故名思义，不到万不得已就不会去实例化类，也就是说在第一次用到类实例的时候才会去实例化，被归为懒汉实现
*/

#include<iostream>
#include<mutex>
std::mutex mt;
class Singleton{
public:
	static Singleton* getInstance();
	~Singleton(){}
	int add(int a, int b){
		return a + b;
	}

private :
	static Singleton* m_pSingleton;
	Singleton(){}
	Singleton(const Singleton&obj) = delete;
	Singleton& operator = (const Singleton &obj) = delete;
};

Singleton* Singleton::m_pSingleton = NULL;

Singleton* Singleton::getInstance()
{
	if (m_pSingleton == NULL)
	{
		mt.lock();
		m_pSingleton = new Singleton();
		mt.unlock();
	}
	return m_pSingleton;
}

