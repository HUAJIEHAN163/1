#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//string���캯��
/*
-string();                   ����һ���յ��ַ��� ��string str;
--string(const char* s);     ʹ���ַ���s��ʼ��
-string(const string& str);  ʹ��һ��string������ʼ����һ��string�����
-string(int n, char c);      ʹ��n���ַ�c��ʼ��
*/

void test01()
{
	string s1;

	const char* str = "hello";
	string s2(str);

	string s3(s2);

	string s4(10, 'a');//���10��a
}

//string��ֵ����
/*
string& operator=(const char* s); //char*�����ַ��� ��ֵ����ǰ���ַ���
string& operator=(const string &s); //���ַ���s������ǰ���ַ���
string& operator=(char c); //�ַ���ֵ����ǰ���ַ���
string& assign(const char *s); //���ַ���s������ǰ���ַ���
string& assign(const char *s, int n); //���ַ���s��ǰn���ַ�������ǰ���ַ���
string& assign(const string &s); //���ַ���s������ǰ�ַ���
string& assign(int n, char c); //��n���ַ�c������ǰ�ַ���
*/