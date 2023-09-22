#include<string>
#include<iostream>
using namespace std;
#include"head.h"
class Person 
{
public:
	//无参构造函数（默认构造）
	Person()
	{
		a = 10;
	}
	//有参构造函数
	Person(int b)
	{
		a = b;
	}
	//拷贝构造函数
	Person(const Person& p)
	{
		a = p.a;
	}

	//析构函数
	~Person()
	{
	
	}
	int a;
};

//调用
void test()
{
	//括号法
	Person p1;//无参（默认）；注意不要加()，否则编译器会作为一个省略void的函数声明来处理，而不是创建对象
	Person p2(10);//有参
	Person p3(p2);//拷贝

	//显示法
	Person p4;
	Person p5 = Person(10);//匿名对象赋予给p5
	Person p6 = Person(p2);

	//隐式法
	Person p7 = 10;
	return;
}

//以下几种情况，拷贝构造函数会被自动调用
//1.使用已经创建好的对象来初始化新对象
void test02()
{
	Person p1(10);
	Person p2(p1);
}

//2.值传递的方式给函数参数传值
//相当于Person p1 = p;
void doWork(Person p1) {}
void test03() {
	Person p; //无参构造函数
	doWork(p);
}

//3. 以值方式返回局部对象
Person doWork2()
{
	Person p1;
	cout << (int*)&p1 << endl;
	return p1;
}
void test04()
{
	Person p = doWork2();
	cout << (int*)&p << endl;
}