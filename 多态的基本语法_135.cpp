#include<iostream>
#include<string>
using namespace std;
#include"head.h"
//静态多态：函数地址早绑定 - 编译阶段确定函数地址
//动态多态：函数地址晚绑定 - 运行阶段确定函数地址
class animal 
{
public:
	//静态多态 最终调用的是父类中的函数
	//void speak()
	//{
	//	cout << "动物叫" << endl;
	//}

	//动态多态 
	//调用条件：1.父类中使用 virtual关键字 （子类可用可不用）2.子类中完全复制父类中的成员函数
	//调用方法：使用父类类型的指针或引用，但是使用时参数为子类（父类指针或引用指向子类对象）
	//结果：调用的是子类中的成员函数
	virtual void speak()
	{
		cout << "动物叫" << endl;
	}
};

class dog :public animal
{
	void speak()
	{
		cout << "小狗叫" << endl;
	}
};

class cat :public animal
{
	void speak()
	{
		cout << "小猫叫" << endl;
	}
};

void doSpeak(animal & animal)
{
	animal.speak();
	return;
}

class Base
{
public:
	virtual void func(Base & p) 
	{
		cout << "Base" << p.a << endl;
	}
	int a = 0;
};

class son:public Base
{
public:
	virtual void func(Base& p)
	{
		cout << "son" << p.a << endl;
	}
	int a = 10;
};
void test135_1()
{
	cat cat;
	dog dog;
	son p;
	son p2;
	Base p3;
	doSpeak(cat);
	doSpeak(dog);
	p.func(p2);
	system("pause");
	return;
}