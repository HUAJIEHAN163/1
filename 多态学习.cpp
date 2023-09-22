#include<iostream>
#include<string>
using namespace std;
#include"head.h"

class CCreat
{
public:
	int power;
	int life;

	virtual void attack(CCreat & p) {}
	virtual void fightback(CCreat& p){}
};

class Dragon :public CCreat
{
public:
	Dragon() 
	{
		life = 1000;
		power = 10;
	}

	virtual void attack(CCreat& p) 
	{
		p.fightback(*this);
	}
	virtual void fightback(CCreat& p)
	{
		life -= (p.power)/2;
	}
};

class Bird :public CCreat
{
public:
	Bird() 
	{
		life = 500;
		power = 5;
	}

	virtual void attack(CCreat& p)
	{
		p.fightback(*this);
	}
	virtual void fightback(CCreat& p)
	{
		life -= (p.power) / 2;
	}
};

//Dragon::Dragon()
//{
//	life = 1000;
//	power = 10;
//}
//
//Bird::Bird()
//{
//	life = 500;
//	power = 5;
//}

void test00_1()
{
	Dragon dragon;
	Bird bird;
	
	dragon.attack(bird);

	cout << "bird.life = " << bird.life << endl;

	dragon.attack(bird);

	cout << "bird.life = " << bird.life << endl;

	dragon.attack(bird);

	cout << "bird.life = " << bird.life << endl;

	system("pause");
	return;
}