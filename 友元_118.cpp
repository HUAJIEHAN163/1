#include<iostream>
#include<string>
using namespace std;
#include "head.h"

class Building {
	//类做友元
	friend class goodgay;
	//全局函数做友元（注意形参也需要写）
	//friend void goodgay((Building * building);
	//类的成员函数做友元
	//friend void goodGay::visit();
public:
	Building() {
		sittingroom = "客厅";
		bedromm = "卧室";
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
	//类外定义函数实体则类内不用定义函数（{}不需要）
	void visit();

private:
	//Building *building;
	Building building;

};

//前面需要有函数返回值的类型 void
void goodgay::visit() {
	//cout << building->sittingroom << endl;
	//cout << building->bedromm << endl;
	cout << building.sittingroom << endl;
	cout << building.bedromm << endl;
}
void test118_1()
{
	goodgay guster;
	//需要有函数()
	guster.visit();
	system("pause");
	return;
}