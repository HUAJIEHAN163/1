#include<iostream>
#include<string>
using namespace std;
#include "head.h"

class Building {
	//������Ԫ
	friend class goodgay;
	//ȫ�ֺ�������Ԫ��ע���β�Ҳ��Ҫд��
	//friend void goodgay((Building * building);
	//��ĳ�Ա��������Ԫ
	//friend void goodGay::visit();
public:
	Building() {
		sittingroom = "����";
		bedromm = "����";
	}

	string sittingroom;

private:
	string bedromm;
};

class goodgay {
public:
	goodgay() {
		//building = new Building;
	}
	//���ⶨ�庯��ʵ�������ڲ��ö��庯����{}����Ҫ��
	void visit();

private:
	//Building *building;
	Building building;

};

//ǰ����Ҫ�к�������ֵ������ void
void goodgay::visit() {
	//cout << building->sittingroom << endl;
	//cout << building->bedromm << endl;
	cout << building.sittingroom << endl;
	cout << building.bedromm << endl;
}
void test118_1()
{
	goodgay guster;
	//��Ҫ�к���()
	guster.visit();
	system("pause");
	return;
}