#include <string>
#include<iostream>
using namespace std;

//��ģ��
//��ģ��ͺ���ģ���﷨���ƣ�������ģ��template������࣬�����Ϊ��ģ��
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
	// ָ��NameType Ϊstring���ͣ�AgeType Ϊ int����
	Person<string, int>P1("�����", 999);
	P1.showPerson();
}


//��ģ���뺯��ģ��������Ҫ�����㣺
//1. ��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
//2. ��ģ����ģ������б��п�����Ĭ�ϲ���
//��ģ��
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
//1����ģ��û���Զ������Ƶ���ʹ�÷�ʽ
void test01()
{
	// Person p("�����", 1000); // ���� ��ģ��ʹ��ʱ�򣬲��������Զ������Ƶ�
	Person <string, int>p("�����", 1000); //����ʹ����ʾָ�����͵ķ�ʽ��ʹ����ģ��
	p.showPerson();
}
//2����ģ����ģ������б��п�����Ĭ�ϲ���
//void test02()
//{
//	Person <string>p("��˽�", 999); //��ģ���е�ģ������б� ����ָ��Ĭ�ϲ���
//	p.showPerson();
//}



//��ģ���г�Ա��������ͨ���г�Ա��������ʱ����������ģ�
//��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
//��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���
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
	//��ģ���еĳ�Ա������������һ��ʼ�ʹ����ģ�������ģ�����ʱ������
	void fun1() { obj.showPerson1(); }
	void fun2() { obj.showPerson2(); }
};
void test01()
{
	MyClass<Person1> m;
	m.fun1();
	//m.fun2();//��������˵���������òŻ�ȥ������Ա����
}