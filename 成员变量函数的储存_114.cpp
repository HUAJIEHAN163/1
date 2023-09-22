#include<iostream>
#include<string>
using namespace std;
#include"head.h"

//只有非静态成员变量才属于类的对象上
class Person 
{
public:
	Person()
	{
		m_heigh = 160;
	}
	//静态成员变量不占对象空间
	static int m_age;
	//非静态成员变量占对象空间
	int m_heigh;

	//函数也不占对象空间，所有函数共享一个函数实例
	static void sfunc()
	{}
	//静态成员函数也不占对象空间
	void func()
	{
		cout << "m_heigh=" << this->m_heigh << endl;
	}
};

//如果在不同文件中对同一静态成员变量进行类外初始化，
//编译器会在连接所有目标文件时发现多个定义，
//从而导致链接错误（如重复定义符号）。
//解决方法是将静态成员变量的定义和初始化放在一个源文件中，
//而在其他源文件中仅进行声明。这样可以确保静态成员变量只有一个定义，并避免链接错误。
//int Person::m_age = 100;

void test114_1()
{
	Person P;
	P.func();
	cout << sizeof(Person) << endl;
	system("pause");
	return;
}