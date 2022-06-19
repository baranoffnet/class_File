#include <iostream>
#include <Windows.h>
#include "file.cpp"
#include <stack>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string path = "1.txt";
	File file1(path);
	file1.printFile();
	file1.addToFile("new line");
	file1.printFile();
	cout << file1.countString()<<endl;
	file1.clearFile();
	cout << "NULL"<<endl;
	file1.printFile();
}

