#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	//1��������һ������
	//2����̬����ֻ���Ե��þ�̬����
	static void func()
	{
		m_age = 100;
		//m_height = 160;//���󣬾�̬����ֻ���Ե��þ�̬����
	}
	//���ж�����ͬһ������
	//���������������ʼ��
	//����׶ο����ڴ�
	static int m_age;
	int m_height;
};

int Person::m_age = 100;

void test113_1()
{
	Person P;
	cout << P.m_age << endl;

	Person P2;
	P2.m_age = 90;
	//���ж�����ͬһ������
	cout << P.m_age << endl;

	system("pause");
	return;
}

void test113_2()
{
	//��̬��Ա�������κ�һ���������ж�����ͬһ������
	//���ʵķ�ʽ������ ������� ��������
	//�������
	Person P;
	P.func();
	cout << P.m_age << endl;

	//��������
	Person::func();
	cout << Person::m_age << endl;

	system("pause");
	return;
}