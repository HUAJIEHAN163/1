#include<iostream>
#include<string>
using namespace std;
#include"head.h"

//thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
class Person1 {
public:
	int age;

	void func(int age)
	{
		//thisָ���÷�1�����βκͳ�Ա����ͬ��ʱ������thisָ��������
		this->age = age;
	}
};

class Person2 {
public:
	int age;
	// ����ֵ��Ҫ������,����ֻ���һ��
	// �����õķ�ʽ���ر��壬����������ص���ֵ���ձ��崴���˿��������µĶ��󣨲ο��������캯����
	//Person2 personaddage(Person2 &p) {
	Person2 &personaddage(Person2 &p) {
		this->age += p.age;
		//thisָ���÷�2�����ض�����
		return *this;
	}
};
void test115_1()
{
	Person2 p1;
	Person2 p2;
	p1.age = 10;
	p2.age = 10;
	//��ʽ���˼��
	p2.personaddage(p1).personaddage(p1).personaddage(p1).personaddage(p1);
	cout << p2.age << endl;
	cout << p1.age << endl;
	system("pause");
}