#include<string>
#include<iostream>
using namespace std;
#include"head.h"

class Person
{
public:
	//��ͳ��ʼ������
	//Person(int a, int b, int c)
	//{
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}

	//�б��ʼ��:���캯��(ֵ1,ֵ2):����1��ֵ1��,����2��ֵ2��
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}
private:
	int m_A;
	int m_B;
	int m_C;
};
void test()
{
	Person p(10, 2, 3);
}