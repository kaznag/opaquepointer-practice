#include "stdafx.h"
#include "FooImpl.h"

namespace FooLib
{
	FooImpl::FooImpl(void)
		: count(0)
	{
	}

	FooImpl::~FooImpl(void)
	{
	}

	void FooImpl::Bump(void)
	{
		this->count++;
	}
}
