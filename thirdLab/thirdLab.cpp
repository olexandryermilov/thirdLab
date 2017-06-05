#include "stdafx.h"
#include <iostream>

int globalVariable;
static int staticGlobalVariable;

void f1(int t)
{
	static int a = 0;
	static int b = 0;
	auto localVariable = 0;
	if (t == 2)
	{
		std::cout << &localVariable << std::endl;
		std::cout << &a << std::endl;
		std::cout << &b << std::endl;
		std::cout << &t << std::endl;
		return;
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
	std::cout << &localStaticObject << std::endl;
	std::cout << &t << std::endl;
	//std::cout << &(t.method) << std::endl;
	std::cout << &(newClass::staticMethod) << std::endl;
}

int main()
{
	int* t = new int(5);
	std::cout << &globalVariable<<std::endl;
	std::cout << &staticGlobalVariable << std::endl;
	f1(1);
	std::cout << t << std::endl;

	std::cout << &globalObject<<std::endl;
	static newClass staticObject;
	std::cout << &staticObject<<std::endl;
	auto autoObject = newClass();
	std::cout << &autoObject<<std::endl;

	newClass tt;
	tt.data = 1;
	f2(tt);
	std::cout << &f2<<std::endl;
	system("pause");
    return 0;
}

