#include<iostream>
#include<string>
using namespace std;
#include"head.h"

//ͬ���̳�
class Base {
public:
	void func() {}
	int m_A;
};

class son :public Base {
public:
	void func() {}
	int m_A;
};

//�̳��е�ͬ����Ա����
void test132_1() {
	son p1;
	//�����Ա����/��������
	p1.m_A = 100;
	p1.func();
	//�����Ա����/��������
	p1.Base::m_A = 200;
	p1.Base::func();
	system("pause");
	return;
}

//���μ̳�
//------ ���� ------
//--����1--����2----
//------����3-------
class animal {
public:
	int m_Age;
};

class sheep :public animal {

};

class tuo :public animal {


};
//һ����̳ж����
class sheeptuo :public sheep, public tuo {

};

//��̳�
//�ڼ̳�֮ǰ���� virtual �ؼ���
class sheep2 :virtual public animal {

};

class tuo2 :virtual public animal {


};
//һ����̳ж����
class sheeptuo2 :public sheep2, public tuo2 {

};

void test132_2()
{
	sheeptuo st;
	st.sheep::m_Age = 18;
	st.tuo::m_Age = 28;
	//���������μ̳е�ʱ����������������ͬ�ĳ�Ա���ԣ�����ͨ���������������
	cout << "st.sheep::m_Age =" << st.sheep::m_Age << endl;
	cout << "st.tuo::m_Age =" << st.tuo::m_Age << endl;

	//�����������ֻ��Ҫһ�ݼ��ɣ��˴���Ҫʹ����̳������
	//�ڼ̳�֮ǰ���� virtual �ؼ���
	sheeptuo2 st2;
	st2.sheep2::m_Age=18;
	st2.tuo2::m_Age = 28;
	cout << "st2.sheep2::m_Age =" << st2.sheep2::m_Age << endl;
	cout << "st2.tuo2::m_Age =" << st2.tuo2::m_Age << endl;

	system("pause");
	return;
}