#include <string>
#include<iostream>
using namespace std;

//类模板
//类模板和函数模板语法相似，在声明模板template后面加类，此类称为类模板
template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};
void test01()
{
	// 指定NameType 为string类型，AgeType 为 int类型
	Person<string, int>P1("孙悟空", 999);
	P1.showPerson();
}


//类模板与函数模板区别主要有两点：
//1. 类模板没有自动类型推导的使用方式
//2. 类模板在模板参数列表中可以有默认参数
//类模板
template<class NameType, class AgeType = int>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};
//1、类模板没有自动类型推导的使用方式
void test01()
{
	// Person p("孙悟空", 1000); // 错误 类模板使用时候，不可以用自动类型推导
	Person <string, int>p("孙悟空", 1000); //必须使用显示指定类型的方式，使用类模板
	p.showPerson();
}
//2、类模板在模板参数列表中可以有默认参数
//void test02()
//{
//	Person <string>p("猪八戒", 999); //类模板中的模板参数列表 可以指定默认参数
//	p.showPerson();
//}



//类模板中成员函数和普通类中成员函数创建时机是有区别的：
//普通类中的成员函数一开始就可以创建
//类模板中的成员函数在调用时才创建
class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};
class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};
template<class T>
class MyClass
{
public:
	T obj;
	//类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成
	void fun1() { obj.showPerson1(); }
	void fun2() { obj.showPerson2(); }
};
void test01()
{
	MyClass<Person1> m;
	m.fun1();
	//m.fun2();//编译会出错，说明函数调用才会去创建成员函数
}