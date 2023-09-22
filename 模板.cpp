#include<iostream>
#include<string>
using namespace std;

//template<typename T>
//template --- 声明创建模板
//typename -- - 表面其后面的符号是一种数据类型，可以用class代替
//T-- - 通用的数据类型，名称可以替换，通常为大写字母
// 
// 使用场景
// 利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
//排序规则从大到小，排序算法为选择排序
//分别利用char数组和int数组进行测试
//
// 注意1：
//使用函数模板时，如果用自动类型推导，不会发生自动类型转换,即隐式类型转换
//普通函数

int myAdd01(int a, int b)
{
	return a + b;
}
//函数模板
template<class T>
T myAdd02(T a, T b)
{
	return a + b;
}

//使用函数模板时，如果用自动类型推导，不会发生自动类型转换,即隐式类型转换
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << myAdd01(a, c) << endl; //正确，将char类型的'c'隐式转换为int类型 'c' 对应 ASCII码99
	//myAdd02(a, c); // 报错，使用自动类型推导时，不会发生隐式类型转换
	myAdd02<int>(a, c); //正确，如果用显示指定类型，可以发生隐式类型转换
}


//普通函数与函数模板调用规则
void myPrint(int a, int b)
{
	cout << "调用的普通函数" << endl;
}
template<typename T>
void myPrint(T a, T b)
{
	cout << "调用的模板" << endl;
}
template<typename T>
void myPrint(T a, T b, T c)
{
	cout << "调用重载的模板" << endl;
}
void test01()
{
	//1、如果函数模板和普通函数都可以实现，优先调用普通函数
	// 注意 如果告诉编译器 普通函数是有的，但只是声明没有实现，或者不在当前文件内实现，就会报错找不到
	int a = 10;
	int b = 20;
	myPrint(a, b); //调用普通函数
	//2、可以通过空模板参数列表来强制调用函数模板
	myPrint<>(a, b); //调用函数模板
	//3、函数模板也可以发生重载
	int c = 30;
	myPrint(a, b, c); //调用重载的函数模板
	//4、 如果函数模板可以产生更好的匹配,优先调用函数模板
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2); //调用函数模板
}