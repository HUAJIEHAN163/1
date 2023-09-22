#include<string>
#include<iostream>
using namespace std;
#include"head.h"

class Person
{
public:
	//传统初始化操作
	//Person(int a, int b, int c)
	//{
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}

	//列表初始化:构造函数(值1,值2):属性1（值1）,属性2（值2）
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}
private:
	int m_A;
	int m_B;
	int m_C;
};
void test()
{
	Person p(10, 2, 3);
}