#include<iostream>
#include<string>
using namespace std;

static void speak();

class Animal
{
public:
	virtual void voice() {}
	//virtual void voice()=0;
};

class cat :public Animal
{
public:
	virtual void voice() 
	{
		cout << "cat" << endl;
	}
};

class dog :public Animal
{
public:
	virtual void voice()
	{
		cout << "dog" << endl;
	}
};

void speak()
{
	Animal* animal;//声明一个基类指针

	animal = new cat();//通过基类指针指向voice对象
	animal->voice();// 调用的是cat类中的voice函数
	delete animal;//释放内存

	animal = new dog();
	animal->voice();
	delete animal;

	return;
}

