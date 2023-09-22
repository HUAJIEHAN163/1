//STL������������������㷨�����������º�����������������������ռ�������
//1. �������������ݽṹ���綯̬����vector������list������deque������set��ӳ���map��, ����������ݡ�
//��Щ������Ϊ����ʽ�����͹���ʽ�������� :
//����ʽ����:ǿ��ֵ����������ʽ�����е�ÿ��Ԫ�ؾ��й̶���λ�á� ����ʽ���� : �������ṹ����Ԫ��֮��û��
//�ϸ�������ϵ�˳���ϵ
//
//2. �㷨�����르�ꥺ��algorithms �������ֳ��õ��㷨����sort��find��copy��for_each��
//�㷨��Ϊ : �ʱ��㷨�ͷ��ʱ��㷨��
//�ʱ��㷨����ָ��������л���������ڵ�Ԫ�ص����ݡ����翽�����滻��ɾ���ȵ�
//���ʱ��㷨����ָ��������в�����������ڵ�Ԫ�����ݣ�������ҡ�������������Ѱ�Ҽ�ֵ�ȵ�
//
//3. ���������������������㷨֮��Ľ��ϼ���
//�ṩһ�ַ�����ʹ֮�ܹ�����Ѱ��ĳ�����������ĸ���Ԫ�أ��������豩¶���������ڲ���ʾ��ʽ��
//ÿ�����������Լ�ר���ĵ�����
//������ʹ�÷ǳ�������ָ�룬��ѧ�׶����ǿ�������������Ϊָ��
//����++++++++++++����++++++++++++++++++֧������
//���������++++++�����ݵ�ֻ������++++++ֻ����֧��++�� == ���� =
//���������++++++�����ݵ�ֻд����++++++ֻд��֧��++
//ǰ�������++++++��д������������ǰ�ƽ�������+++��д��֧��++�� == ���� =
//˫�������++++++��д������������ǰ��������+++��д��֧��++��--��
//������ʵ�����++��д��������������Ծ�ķ�ʽ�����������ݣ�������ǿ�ĵ�����+++��д��֧��++��--��[n]�� - n��<��<= ��>�� >=
//
//���õ������е���������Ϊ˫�����������������ʵ�����
//
//4. �º�������Ϊ���ƺ���������Ϊ�㷨��ĳ�ֲ��ԡ�
//
//5. ��������һ�����������������߷º�����������ӿڵĶ�����
//
//6. �ռ�������������ռ�����������

#include<iostream>
#include<string>
using namespace std;
#include<vector>
#include<algorithm>//��׼�㷨��ͷ�ļ�

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

//int����vector����
void test()
{
	vector<int> t;//����һ������

	t.push_back(10);//β�巨��������
	t.push_back(20);
	t.push_back(30);
	t.push_back(40);

	//����forѭ�����б���
	//begin��end���ص���һ������������
	for (vector<int>::iterator v = t.begin(); v != t.end(); v++)
	{
		cout << *v << endl;
	}

	//����STL��׼�㷨
	for_each(t.begin(), t.end(), Myprint);
}
 
//�Զ�������vector����
void test2()
{
	Person person1("aaa", 10);
	Person person2("bbb", 20);

	vector<Person> v;

	v.push_back(person1);
	v.push_back(person2);

	//����forѭ�����б���
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "���֣�" << (*it).M_name << "���䣺" << (*it).M_age << endl;
		//it��ָ��Person���͵�ָ�룬�����ú�(*it)��Person ��ͬ��ʹ�����ȡֵ��ʽ
	}
}

//�Զ���ָ������vector����
void test3()
{
	Person person1("aaa", 10);
	Person person2("bbb", 20);
	//Person���͵�ָ�������������
	vector<Person*> v;

	v.push_back(&person1);
	v.push_back(&person2);

	//����forѭ�����б���
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "���֣�" << (*it)->M_name << "���䣺" << (*it)->M_age << endl;
		//itָ��Person����ָ���ָ�룬�����ú�(*it)��Person *��ͬ��ʹ����ָ���ȡֵ��ʽ
	}
}

//����Ƕ��
void test04()
{
	vector<vector<int>> v;

	vector<int> v1;
	vector<int> v2;

	//�����в�������
	for (int i = 0; i == 4; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	//��С����Ƕ���������
	v.push_back(v1);
	v.push_back(v2);

	for (vector<vector<int>>::iterator t = v.begin(); t != v.end(); t++)
	{
		//*t = vector<int>
		//�������һ��С���������ݣ�������ڶ���С����������
		for (vector<int>::iterator vt = (*t).begin(); vt != (*t).end(); vt++)
		{
			//С����ÿ����֮���ÿո���
			cout << *vt << " ";
		}
		//ÿ��С����֮���û���
		cout << endl;
	}
}



//���������㷨�Ľ��

class GreaterFive
{
public:
	//����һ����Ա����operator()��������һ����������val��������һ������ֵ��true��false��
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

	//find_if�������εı���������Ԫ�أ����ص�һ��ʹ����Ϊtrue��Ԫ�صĵ��������������ʧ���򷵻�end������
	//GreaterFive()������һ����ʱ��GreaterFive����󣬲����ö�����Ϊν�ʴ��ݸ�find_if�㷨
	//�ڴ�����ʱ����Ĺ��̵���ͬʱ������()�����
	//operator()��()���������������
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive());
	if (pos == v.end())
	{
		cout << "δ�ҵ���" << endl;
	}
	else
	{
		//�����һ������5����
		cout << "�ҵ�>5�����֣�" << *pos << endl;
		//���ȫ������5����
		while (pos != v.end())
		{
			cout << *pos++ << " " << endl;
		}
	}
}
