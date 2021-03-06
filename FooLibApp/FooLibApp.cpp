// FooLibApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "FooLib.h"
#include <iostream>

int main()
{
	int result = 0;
	FooRef fooRef;
	result = fooInitialize(&fooRef);
	if (result != 0) {
		return -1;
	}

	result = fooBump(fooRef);
	result = fooBump(fooRef);

	int count = 0;
	result = fooGetCount(fooRef, &count);
	if (result == 0) {
		printf("count: %d\n", count);
	}

	result = fooTerminate(fooRef);

	return 0;
}
