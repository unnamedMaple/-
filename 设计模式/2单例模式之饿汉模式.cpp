/*
�����ඨ���ʱ��ͽ���ʵ����
*/

class Singleton{
public :
	static Singleton* getInstance();
	int add(int a, int b)
	{
		return a + b;
	}
private :
	Singleton(){

	}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Singleton* m_pSingleton;
};

Singleton* Singleton::m_pSingleton = new Singleton();

Singleton* Singleton::getInstance()
{
	return m_pSingleton;
}

