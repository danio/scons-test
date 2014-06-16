#include "stdafx.h"
#include <iostream>
#include <string>
#include "module1/SampleClassA.h"

using namespace SampleLibrary;

#ifdef WIN32
int _tmain(int argc, _TCHAR* argv[], _TCHAR** envp)
#else
int main(int argc, char* argv[], char** envp)
#endif
{
	std::cout << "Hello" << std::endl;

	SampleClassA a;
	a.SetValue(42);
	std::cout << "Did you know? " << a.GetValue() << std::endl;

	return 0;
}
