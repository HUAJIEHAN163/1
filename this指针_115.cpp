#include<iostream>
#include<string>
using namespace std;
#include"head.h"

//this指针指向被调用的成员函数所属的对象
class Person1 {
public:
	int age;

	void func(int age)
	{
		//this指针用法1：当形参和成员变量同名时，可用this指针来区分
		this->age = age;
	}
};

class Person2 {
public:
	int age;
	// 返回值需要用引用,否则只会加一次
	// 用引用的方式返回本体，但是如果返回的是值则按照本体创建了拷贝，即新的对象（参考拷贝构造函数）
	//Person2 personaddage(Person2 &p) {
	Person2 &personaddage(Person2 &p) {
		this->age += p.age;
		//this指针用法2：返回对象本身
		return *this;
	}
};
void test115_1()
{
	Person2 p1;
	Person2 p2;
	p1.age = 10;
	p2.age = 10;
	//链式编程思想
	p2.personaddage(p1).personaddage(p1).personaddage(p1).personaddage(p1);
	cout << p2.age << endl;
	cout << p1.age << endl;
	system("pause");
}