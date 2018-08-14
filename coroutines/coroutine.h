#ifndef __COROUTINE__H__
#define __COROUTINE__H__
typedef void(*coroutine_function)(void*);

void coroutine_new(coroutine_function f, void* arg);
void coroutine_yield();
void coroutine_main();
#endif // !__COROUTINE__H__
