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
	Animal* animal;//����һ������ָ��

	animal = new cat();//ͨ������ָ��ָ��voice����
	animal->voice();// ���õ���cat���е�voice����
	delete animal;//�ͷ��ڴ�

	animal = new dog();
	animal->voice();
	delete animal;

	return;
}

