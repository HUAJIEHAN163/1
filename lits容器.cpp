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

	//L1[0] ��������[]����list�����е�Ԫ��
	//L1.at(0) ��������at����list�����е�Ԫ��

	cout << "��һ��Ԫ���� " << L1.front() << endl;
	cout << "���һ��Ԫ���� " << L1.back() << endl;

	list<int>::iterator it = L1.begin();
	//it = it +n; ��֧�ּӺŻ��߼������������֧��������ʣ�ͨ�����ַ�ʽ�����ж������Ƿ�֧���������
	it++;//����֧����++����--��˵������֧��˫�����
	cout << *(it) << endl;
	return;

}