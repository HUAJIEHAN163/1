#include<iostream>
#include<string>
#include"head.h"
using namespace std;

class Base
{
public:
	Base() {
		m_A = 0;
	}
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class son1:public Base
{
public:
	void func()
	{
		m_A = 100;//�����̳�ʱ���������Ա��̳�Ϊ��������
		m_B = 100;//�����̳�ʱ���������Ա��̳�Ϊ��������
		//m_C = 100;//�����̳�ʱ��˽�����Ա��̳�Ϊ˽������
	}	
	int m_A = 300;
};

class son2 :protected Base
{
public:
	void func()
	{
		m_A = 100;//�����̳�ʱ���������Ա��̳�Ϊ��������
		m_B = 100;//�����̳�ʱ���������Ա��̳�Ϊ��������
		//m_C = 100;//�����̳�ʱ��˽�����Ա��̳�Ϊ˽������
	}
};

class son3 : private Base
{
public:
	void func()
	{
		m_A = 100;//˽�м̳�ʱ���������Ա��̳�Ϊ˽������
		m_B = 100;//˽�м̳�ʱ���������Ա��̳�Ϊ˽������
		//m_C = 100;//�����̳�ʱ��˽�����Ա��̳�Ϊ˽������
	}
};
void test127_1()
{
	son1 p1;
	cout << "p1.m_A = " << p1.m_A << endl;
	p1.m_A = 200;
	//p1.m_B = 200;//�������������޷�����
	//p1.m_C = 200;//˽�����������޷�����
	cout << "p1.m_A = " << p1.m_A << endl;
	//ͬ�������ִ�У�����͸�������ͬ����Ա����ʱ������.XX ���õ�������Ĳ���������.����::XX���õ�ʱ����Ĳ�����
	cout << "p1.Base::m_A = " << p1.Base::m_A << endl;
	p1.func();
	cout << "ִ��func����"<< endl;
	cout << "p1.m_A = " << p1.m_A << endl;
	cout << "p1.Base::m_A = " << p1.Base::m_A << endl;

	son2 p2;
	//p2.m_A = 200;//�������������޷�����
	//p2.m_B = 200;//�������������޷�����
	//p2.m_C = 200;//˽�����������޷�����

	son3 p3;
	//p3.m_A = 200;//˽�����������޷�����
	//p3.m_B = 200;//˽�����������޷�����
	//p3.m_C = 200;//˽�����������޷�����

	system("pause");
	return;
}