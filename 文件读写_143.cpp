#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include"head.h"
#include<windows.h>

void test143_1()
{
	/*ʹ�ÿ��ַ��ַ������ַ�������ֵʱ����Ҫ���ַ���ǰ�����Lǰ׺����ʶ����һ�����ַ��ַ�����*/
	LPCWSTR folderPath = L"D:/vs/examplefolder";
	/*�����ļ���*/
	//if (CreateDirectory(folderPath, NULL)) {
	//	cout << "�ļ����Ѵ�����" << folderPath << endl;
	//}
	//else {
	//	cout << "�޷������ļ��У�" << folderPath << endl;
	//}
	/*�����ļ� ��б��/ */
	ofstream ofile1("D:/vs/examplefolder/example1.txt",ios::out);
	/*�����ļ� б��\\����������ת���ַ� \��*/
	ofstream ofile2("D:\\vs\\examplefolder\\example2.txt");

	ofile1 << "�豸����JEL"<<endl;

	ofile1.close();

	ifstream ifile1;
	ifile1.open("D:/vs/examplefolder/example1.txt",ios::in);
	if (ifile1.is_open() == NULL)
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//��һ�ַ�ʽ
//char buf[1024] = { 0 };
//while (ifile1 >> buf)
//{
// cout << buf << endl;
//}
//�ڶ���
//char buf[1024] = { 0 };
//while (ifile1.getline(buf,sizeof(buf)))
//{
// cout << buf << endl;
//}
//������
string buf;
while (getline(ifile1, buf))
{
 cout << buf << endl;
}
	//char c;
	//while ((c = ifile1.get()) != EOF)
	//{
	//		cout << c << endl;
	//}
	ifile1.close();
	return;

}