#include "stdafx.h"
#include <iostream>

int globalVariable;
static int staticGlobalVariable;

void f1(int t)
{
	static int a = 0;
	static int b = 0;
	std::cout << "Iteration " << t << std::endl;
	auto localVariable = 0;
	if (t <= 2)
	{
		std::cout <<"Auto Local Variable "<< &localVariable << std::endl;
		std::cout <<"Static Local Variable "<< &a << std::endl;
		std::cout << "Static Variable " << &b << std::endl;
		std::cout <<"Parameter: " << &t << std::endl;
		if(t==2)return;
	}
	f1(t + 1);
}

class newClass
{
   public:	
	    int data;
		void method()
		{
			data++;
		}
		static void staticMethod()
		{
		}
};

newClass globalObject;

void f2(newClass t)
{
	static newClass localStaticObject;
	std::cout <<"Local Static Object "<< &localStaticObject << std::endl;
	std::cout << "Object-Parameter "<< &t << std::endl;
	std::cout <<"Method "<< &newClass::method << std::endl;
	std::cout <<"Static Method "<< &(newClass::staticMethod) << std::endl;
}

int main()
{
	int* t = new int(5);
	std::cout <<"Global Variable "<< &globalVariable<<std::endl;
	std::cout <<"Static Global Variable "<< &staticGlobalVariable << std::endl;
	f1(1);
	std::cout <<"Dynamic Variable "<< t << std::endl;

	std::cout <<"Global Object "<< &globalObject<<std::endl;
	static newClass staticObject;
	std::cout <<"Static Object "<< &staticObject<<std::endl;
	auto autoObject = newClass();
	std::cout <<"Auto Object "<< &autoObject<<std::endl;

	newClass tt;
	tt.data = 1;
	f2(tt);
	std::cout <<"Function: "<< &f2<<std::endl;
	system("pause");
    return 0;
}

