#pragma once

namespace FooLib
{
	class FooImpl
	{
	private:
		int count;
	public:
		FooImpl(void);
		~FooImpl(void);
		void Bump(void);
		int GetCount(void) { return this->count; }
	};
}
