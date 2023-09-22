#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	//1，程序共享一个函数
	//2，静态函数只可以调用静态变量
	static void func()
	{
		m_age = 100;
		//m_height = 160;//错误，静态函数只可以调用静态变量
	}
	//所有对象共享同一份数据
	//类内声明，类外初始化
	//编译阶段开辟内存
	static int m_age;
	int m_height;
};

int Person::m_age = 100;

void test113_1()
{
	Person P;
	cout << P.m_age << endl;

	Person P2;
	P2.m_age = 90;
	//所有对象共享同一份数据
	cout << P.m_age << endl;

	system("pause");
	return;
}

void test113_2()
{
	//静态成员不属于任何一个对象，所有对象共享同一份数据
	//访问的方式有两种 对象访问 类名访问
	//对象访问
	Person P;
	P.func();
	cout << P.m_age << endl;

	//类名访问
	Person::func();
	cout << Person::m_age << endl;

	system("pause");
	return;
}