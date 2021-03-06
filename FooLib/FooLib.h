#pragma once

#ifdef FOOLIB_EXPORTS
#define FOOLIB_API __declspec(dllexport)
#else
#define FOOLIB_API __declspec(dllimport)
#endif // FOOLIB_EXPORTS

typedef struct __FooObject* FooRef;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	FOOLIB_API int fooInitialize(FooRef* outFoo);

	FOOLIB_API int fooTerminate(FooRef inFoo);

	FOOLIB_API int fooBump(FooRef inFoo);

	FOOLIB_API int fooGetCount(FooRef inFoo, int* outCount);
#ifdef __cplusplus
}
#endif // __cplusplus
