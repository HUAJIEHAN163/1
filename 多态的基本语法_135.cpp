#include<iostream>
#include<string>
using namespace std;
#include"head.h"
//��̬��̬��������ַ��� - ����׶�ȷ��������ַ
//��̬��̬��������ַ��� - ���н׶�ȷ��������ַ
class animal 
{
public:
	//��̬��̬ ���յ��õ��Ǹ����еĺ���
	//void speak()
	//{
	//	cout << "�����" << endl;
	//}

	//��̬��̬ 
	//����������1.������ʹ�� virtual�ؼ��� ��������ÿɲ��ã�2.��������ȫ���Ƹ����еĳ�Ա����
	//���÷�����ʹ�ø������͵�ָ������ã�����ʹ��ʱ����Ϊ���ࣨ����ָ�������ָ���������
	//��������õ��������еĳ�Ա����
	virtual void speak()
	{
		cout << "�����" << endl;
	}
};

class dog :public animal
{
	void speak()
	{
		cout << "С����" << endl;
	}
};

class cat :public animal
{
	void speak()
	{
		cout << "Сè��" << endl;
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