#include<iostream>
#include<string>
#include "head.h"
using namespace std;

class Person {
public:
	//类成员函数做运算符重载
	//Person operator+ (Person& p) {
	//	Person temp;
	//	temp.m_A = this->m_A + p.m_A;
	//	return temp;
	//}
	int m_A;
};

//全局函数做运算符重载
Person operator+(Person& p1, Person& p2) {
	Person temp;
	p1.m_A = 10;
	p2.m_A = 10;

	temp.m_A = p1.m_A + p2.m_A;
	return temp;
}
void test121_1() {
	Person p1;
	p1.m_A = 10;
	Person p2;
	p2.m_A = 10;
	//类成员函数的本质
	//Person p3 = p1.operator+(p2);
	//全局函数的本质
	Person p3 = operator+(p1, p2);
	//Person p3 = p1 + p2;
	cout << p3.m_A << endl;
	//运算符重载也可以发生函数重载
	//p3 = person +int;
	system("pause");
	return;
}