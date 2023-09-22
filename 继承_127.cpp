#include<iostream>
#include<string>
#include"head.h"
using namespace std;

class Base
{
public:
	Base() {
		m_A = 0;
	}
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class son1:public Base
{
public:
	void func()
	{
		m_A = 100;//公共继承时，公共属性被继承为公共属性
		m_B = 100;//公共继承时，保护属性被继承为保护属性
		//m_C = 100;//公共继承时，私有属性被继承为私有属性
	}	
	int m_A = 300;
};

class son2 :protected Base
{
public:
	void func()
	{
		m_A = 100;//保护继承时，公共属性被继承为保护属性
		m_B = 100;//保护继承时，保护属性被继承为保护属性
		//m_C = 100;//保护继承时，私有属性被继承为私有属性
	}
};

class son3 : private Base
{
public:
	void func()
	{
		m_A = 100;//私有继承时，公共属性被继承为私有属性
		m_B = 100;//私有继承时，保护属性被继承为私有属性
		//m_C = 100;//公共继承时，私有属性被继承为私有属性
	}
};
void test127_1()
{
	son1 p1;
	cout << "p1.m_A = " << p1.m_A << endl;
	p1.m_A = 200;
	//p1.m_B = 200;//保护属性类外无法调用
	//p1.m_C = 200;//私有属性类外无法调用
	cout << "p1.m_A = " << p1.m_A << endl;
	//同名类参数执行（子类和父类中有同名成员参数时，对象.XX 调用的是子类的参数，对象.父类::XX调用的时父类的参数）
	cout << "p1.Base::m_A = " << p1.Base::m_A << endl;
	p1.func();
	cout << "执行func函数"<< endl;
	cout << "p1.m_A = " << p1.m_A << endl;
	cout << "p1.Base::m_A = " << p1.Base::m_A << endl;

	son2 p2;
	//p2.m_A = 200;//保护属性类外无法调用
	//p2.m_B = 200;//保护属性类外无法调用
	//p2.m_C = 200;//私有属性类外无法调用

	son3 p3;
	//p3.m_A = 200;//私有属性类外无法调用
	//p3.m_B = 200;//私有属性类外无法调用
	//p3.m_C = 200;//私有属性类外无法调用

	system("pause");
	return;
}