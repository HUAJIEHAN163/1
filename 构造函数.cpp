#include<string>
#include<iostream>
using namespace std;
#include"head.h"
class Person 
{
public:
	//�޲ι��캯����Ĭ�Ϲ��죩
	Person()
	{
		a = 10;
	}
	//�вι��캯��
	Person(int b)
	{
		a = b;
	}
	//�������캯��
	Person(const Person& p)
	{
		a = p.a;
	}

	//��������
	~Person()
	{
	
	}
	int a;
};

//����
void test()
{
	//���ŷ�
	Person p1;//�޲Σ�Ĭ�ϣ���ע�ⲻҪ��()���������������Ϊһ��ʡ��void�ĺ������������������Ǵ�������
	Person p2(10);//�в�
	Person p3(p2);//����

	//��ʾ��
	Person p4;
	Person p5 = Person(10);//�����������p5
	Person p6 = Person(p2);

	//��ʽ��
	Person p7 = 10;
	return;
}

//���¼���������������캯���ᱻ�Զ�����
//1.ʹ���Ѿ������õĶ�������ʼ���¶���
void test02()
{
	Person p1(10);
	Person p2(p1);
}

//2.ֵ���ݵķ�ʽ������������ֵ
//�൱��Person p1 = p;
void doWork(Person p1) {}
void test03() {
	Person p; //�޲ι��캯��
	doWork(p);
}

//3. ��ֵ��ʽ���ؾֲ�����
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