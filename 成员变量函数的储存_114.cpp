#include<iostream>
#include<string>
using namespace std;
#include"head.h"

//ֻ�зǾ�̬��Ա������������Ķ�����
class Person 
{
public:
	Person()
	{
		m_heigh = 160;
	}
	//��̬��Ա������ռ����ռ�
	static int m_age;
	//�Ǿ�̬��Ա����ռ����ռ�
	int m_heigh;

	//����Ҳ��ռ����ռ䣬���к�������һ������ʵ��
	static void sfunc()
	{}
	//��̬��Ա����Ҳ��ռ����ռ�
	void func()
	{
		cout << "m_heigh=" << this->m_heigh << endl;
	}
};

//����ڲ�ͬ�ļ��ж�ͬһ��̬��Ա�������������ʼ����
//������������������Ŀ���ļ�ʱ���ֶ�����壬
//�Ӷ��������Ӵ������ظ�������ţ���
//��������ǽ���̬��Ա�����Ķ���ͳ�ʼ������һ��Դ�ļ��У�
//��������Դ�ļ��н�������������������ȷ����̬��Ա����ֻ��һ�����壬���������Ӵ���
//int Person::m_age = 100;

void test114_1()
{
	Person P;
	P.func();
	cout << sizeof(Person) << endl;
	system("pause");
	return;
}