#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//string构造函数
/*
-string();                   创建一个空的字符串 如string str;
--string(const char* s);     使用字符串s初始化
-string(const string& str);  使用一个string类对象初始化另一个string类对象
-string(int n, char c);      使用n个字符c初始化
*/

void test01()
{
	string s1;

	const char* str = "hello";
	string s2(str);

	string s3(s2);

	string s4(10, 'a');//输出10个a
}

//string赋值操作
/*
string& operator=(const char* s); //char*类型字符串 赋值给当前的字符串
string& operator=(const string &s); //把字符串s赋给当前的字符串
string& operator=(char c); //字符赋值给当前的字符串
string& assign(const char *s); //把字符串s赋给当前的字符串
string& assign(const char *s, int n); //把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s); //把字符串s赋给当前字符串
string& assign(int n, char c); //用n个字符c赋给当前字符串
*/