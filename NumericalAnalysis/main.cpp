//#include <iostream>
//#include<memory>
//using namespace std;
//
//class Complax
//{
//public:
//	Complax(int a = 0, int b = 0)
//	{
//		this->a = a;
//		this->b = b;
//	}
//	void printC()
//	{
//		cout << "a = " << a << "\tb = " << b << endl;
//	}
//	~Complax()
//	{
//	}
//	//private:
//public:
//
//	int a;
//	int b;
//
//};
//// 1����ȫ�ֺ���
//Complax myAdd(Complax &c1, Complax &c2)
//{
//	Complax temp(c1.a + c2.a, c1.b + c2.b);
//	return temp;
//}
//// 2����������
//Complax operator+(Complax &c1, Complax &c2)
//{
//	Complax temp(c1.a + c2.a, c1.b + c2.b);
//	return temp;
//}
//int main()
//{
//	shared_ptr<int> p;
//	int a = 0, b = 0;
//	int c; // �������������ͣ��������Ѿ�֪���ˣ��������
//	c = a + b;
//
//	// a + bi;  // �����������
//	Complax c1(1, 2), c2(3, 4);
//	Complax c3;  // 2c3���û��Զ����������ͣ�c++��������֪���������
//				 //    c3 = c1 + c2;
//
//				 // 3c++������Ӧ�ø������ṩһ�ֻ���
//				 // ���Զ����������� �л������ ��������� ==> ���������
//
//				 // 4��������ػ���
//	Complax c4 = myAdd(c1, c2);
//	c4.printC();
//
//	// �������Complax c4 = c1+c2;
//	// Complax c5 = operator+(c1, c2);
//	// c5.printC();
//
//	// ��������
//	Complax c5 = c1 + c2;
//	c5.printC();
//
//	// ��������صı��� ��  ��������
//	return 0;
//}

//#include <stdio.h>      /* fopen, fputs, fclose, stderr */
//#include <stdlib.h>     /* abort, NULL */
#include<iostream>
using namespace std;
int main()
{
	//FILE * pFile;
	//pFile = fopen("E:\\NoteBook\\myfile1.txt", "r");
	//if (pFile == NULL)
	//{
	//	fputs("error opening file\n", stderr);
	//	//abort();
	//	exit(EXIT_FAILURE);
	//}
	//
	///* regular process here */
	//
	//fclose(pFile);
	cout<<getenv("TIME")<<endl;
	return 0;
}