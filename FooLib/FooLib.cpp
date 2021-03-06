// FooLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "FooLib.h"
#include "FooImpl.h"
#include <stdlib.h>

struct __FooObject {
	FooLib::FooImpl* fooImpl;
};

int fooInitialize(FooRef* outFoo)
{
	__FooObject* obj = (__FooObject*)malloc(sizeof(__FooObject));
	if (obj == nullptr) {
		return -1;
	}

	FooLib::FooImpl* foo = new FooLib::FooImpl();
	if (foo == nullptr) {
		return -1;
	}

	obj->fooImpl = foo;
	*outFoo = obj;

	return 0;
}

int fooTerminate(FooRef inFoo)
{
	if (inFoo != nullptr && inFoo->fooImpl != nullptr) {
		delete inFoo->fooImpl;
		inFoo->fooImpl = nullptr;
		free(inFoo);
		inFoo = nullptr;
		return 0;
	}

	return -1;
}

int fooBump(FooRef inFoo)
{
	if (inFoo != nullptr && inFoo->fooImpl != nullptr) {
		inFoo->fooImpl->Bump();
		return 0;
	}

	return -1;
}

int fooGetCount(FooRef inFoo, int* outCount)
{
	if (inFoo != nullptr && inFoo->fooImpl != nullptr) {
		int count = inFoo->fooImpl->GetCount();
		*outCount = count;
		return 0;
	}

	return -1;
}