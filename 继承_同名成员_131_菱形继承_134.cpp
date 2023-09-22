#include<iostream>
#include<string>
using namespace std;
#include"head.h"

//同名继承
class Base {
public:
	void func() {}
	int m_A;
};

class son :public Base {
public:
	void func() {}
	int m_A;
};

//继承中的同名成员处理
void test132_1() {
	son p1;
	//子类成员属性/函数调用
	p1.m_A = 100;
	p1.func();
	//父类成员属性/函数调用
	p1.Base::m_A = 200;
	p1.Base::func();
	system("pause");
	return;
}

//菱形继承
//------ 父类 ------
//--子类1--子类2----
//------子类3-------
class animal {
public:
	int m_Age;
};

class sheep :public animal {

};

class tuo :public animal {


};
//一个类继承多个类
class sheeptuo :public sheep, public tuo {

};

//虚继承
//在继承之前加上 virtual 关键字
class sheep2 :virtual public animal {

};

class tuo2 :virtual public animal {


};
//一个类继承多个类
class sheeptuo2 :public sheep2, public tuo2 {

};

void test132_2()
{
	sheeptuo st;
	st.sheep::m_Age = 18;
	st.tuo::m_Age = 28;
	//当出现菱形继承的时候，且两个父类有相同的成员属性，可以通过作用域加以区分
	cout << "st.sheep::m_Age =" << st.sheep::m_Age << endl;
	cout << "st.tuo::m_Age =" << st.tuo::m_Age << endl;

	//这份数据我们只需要一份即可，此处需要使用虚继承来解决
	//在继承之前加上 virtual 关键字
	sheeptuo2 st2;
	st2.sheep2::m_Age=18;
	st2.tuo2::m_Age = 28;
	cout << "st2.sheep2::m_Age =" << st2.sheep2::m_Age << endl;
	cout << "st2.tuo2::m_Age =" << st2.tuo2::m_Age << endl;

	system("pause");
	return;
}