#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include"head.h"
#include<windows.h>

void test143_1()
{
	/*使用宽字符字符串的字符串字面值时，需要在字符串前面加上L前缀来标识它是一个宽字符字符串。*/
	LPCWSTR folderPath = L"D:/vs/examplefolder";
	/*创建文件夹*/
	//if (CreateDirectory(folderPath, NULL)) {
	//	cout << "文件夹已创建：" << folderPath << endl;
	//}
	//else {
	//	cout << "无法创建文件夹：" << folderPath << endl;
	//}
	/*创建文件 反斜杠/ */
	ofstream ofile1("D:/vs/examplefolder/example1.txt",ios::out);
	/*创建文件 斜杠\\（用于区别转义字符 \）*/
	ofstream ofile2("D:\\vs\\examplefolder\\example2.txt");

	ofile1 << "设备名：JEL"<<endl;

	ofile1.close();

	ifstream ifile1;
	ifile1.open("D:/vs/examplefolder/example1.txt",ios::in);
	if (ifile1.is_open() == NULL)
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//第一种方式
//char buf[1024] = { 0 };
//while (ifile1 >> buf)
//{
// cout << buf << endl;
//}
//第二种
//char buf[1024] = { 0 };
//while (ifile1.getline(buf,sizeof(buf)))
//{
// cout << buf << endl;
//}
//第三种
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