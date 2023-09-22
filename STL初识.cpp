//STL的六大组件：容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器
//1. 容器：各种数据结构，如动态数组vector、链表list、队列deque、集合set、映射表map等, 用来存放数据。
//这些容器分为序列式容器和关联式容器两种 :
//序列式容器:强调值的排序，序列式容器中的每个元素均有固定的位置。 关联式容器 : 二叉树结构，各元素之间没有
//严格的物理上的顺序关系
//
//2. 算法（アルゴリズムalgorithms ）：各种常用的算法，如sort、find、copy、for_each等
//算法分为 : 质变算法和非质变算法。
//质变算法：是指运算过程中会更改区间内的元素的内容。例如拷贝，替换，删除等等
//非质变算法：是指运算过程中不会更改区间内的元素内容，例如查找、计数、遍历、寻找极值等等
//
//3. 迭代器：扮演了容器与算法之间的胶合剂。
//提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方式。
//每个容器都有自己专属的迭代器
//迭代器使用非常类似于指针，初学阶段我们可以先理解迭代器为指针
//种类++++++++++++功能++++++++++++++++++支持运算
//输入迭代器++++++对数据的只读访问++++++只读，支持++、 == 、！ =
//输出迭代器++++++对数据的只写访问++++++只写，支持++
//前向迭代器++++++读写操作，并能向前推进迭代器+++读写，支持++、 == 、！ =
//双向迭代器++++++读写操作，并能向前和向后操作+++读写，支持++、--，
//随机访问迭代器++读写操作，可以以跳跃的方式访问任意数据，功能最强的迭代器+++读写，支持++、--、[n]、 - n、<、<= 、>、 >=
//
//常用的容器中迭代器种类为双向迭代器，和随机访问迭代器
//
//4. 仿函数：行为类似函数，可作为算法的某种策略。
//
//5. 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西。
//
//6. 空间配置器：负责空间的配置与管理。

#include<iostream>
#include<string>
using namespace std;
#include<vector>
#include<algorithm>//标准算法的头文件

void Myprint(int val)
{
	cout << val << endl;
}

class Person
{
public:
	Person(string name, int age)
	{
		M_name = name;
		M_age = age;
	}

	string M_name;
	int M_age;
};

//int类型vector容器
void test()
{
	vector<int> t;//声明一个容器

	t.push_back(10);//尾插法插入数据
	t.push_back(20);
	t.push_back(30);
	t.push_back(40);

	//利用for循环进行遍历
	//begin和end返回的是一个迭代器对象
	for (vector<int>::iterator v = t.begin(); v != t.end(); v++)
	{
		cout << *v << endl;
	}

	//利用STL标准算法
	for_each(t.begin(), t.end(), Myprint);
}
 
//自定义类型vector容器
void test2()
{
	Person person1("aaa", 10);
	Person person2("bbb", 20);

	vector<Person> v;

	v.push_back(person1);
	v.push_back(person2);

	//利用for循环进行遍历
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "名字：" << (*it).M_name << "年龄：" << (*it).M_age << endl;
		//it是指向Person类型的指针，解引用后(*it)和Person 相同，使用类的取值方式
	}
}

//自定义指针类型vector容器
void test3()
{
	Person person1("aaa", 10);
	Person person2("bbb", 20);
	//Person类型的指针存在容器当中
	vector<Person*> v;

	v.push_back(&person1);
	v.push_back(&person2);

	//利用for循环进行遍历
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "名字：" << (*it)->M_name << "年龄：" << (*it)->M_age << endl;
		//it指向Person类型指针的指针，解引用后(*it)和Person *相同，使用类指针的取值方式
	}
}

//容器嵌套
void test04()
{
	vector<vector<int>> v;

	vector<int> v1;
	vector<int> v2;

	//容器中插入数据
	for (int i = 0; i == 4; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	//将小容器嵌套入大容器
	v.push_back(v1);
	v.push_back(v2);

	for (vector<vector<int>>::iterator t = v.begin(); t != v.end(); t++)
	{
		//*t = vector<int>
		//先输出第一个小容器的数据，后输出第二个小容器的数据
		for (vector<int>::iterator vt = (*t).begin(); vt != (*t).end(); vt++)
		{
			//小容器每个数之间用空格间隔
			cout << *vt << " ";
		}
		//每个小容器之间用换行
		cout << endl;
	}
}



//迭代器和算法的结合

class GreaterFive
{
public:
	//定义一个成员函数operator()，它接受一个整数参数val，并返回一个布尔值（true或false）
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test05()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//find_if函数依次的遍历容器的元素，返回第一个使函数为true的元素的迭代器，如果查找失败则返回end迭代器
	//GreaterFive()创建了一个临时的GreaterFive类对象，并将该对象作为谓词传递给find_if算法
	//在创建临时对象的过程当中同时重载了()运算符
	//operator()将()进行了运算符重载
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive());
	if (pos == v.end())
	{
		cout << "未找到！" << endl;
	}
	else
	{
		//输出第一个大于5的数
		cout << "找到>5的数字：" << *pos << endl;
		//输出全部大于5的数
		while (pos != v.end())
		{
			cout << *pos++ << " " << endl;
		}
	}
}
