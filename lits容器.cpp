#include<iostream>
#include<algorithm>
#include<list>
#include<string>
using namespace std;

void test001()
{
	list<int> L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);

	//L1[0] 不可以用[]访问list容器中的元素
	//L1.at(0) 不可以用at访问list容器中的元素

	cout << "第一个元素是 " << L1.front() << endl;
	cout << "最后一个元素是 " << L1.back() << endl;

	list<int>::iterator it = L1.begin();
	//it = it +n; 不支持加号或者减号运算符，不支持随机访问，通过这种方式可以判断容器是否支持随机访问
	it++;//但是支持自++和自--，说明容器支持双向访问
	cout << *(it) << endl;
	return;

}