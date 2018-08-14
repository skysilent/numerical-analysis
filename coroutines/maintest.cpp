#include"coroutine.h"
#include <stdio.h>
#include <assert.h>
#include<iostream>
void co1(void* msg)
{
	for (int i = 0; i != 5; ++i)
	{
		printf("%s\n", (char*)msg);
		coroutine_yield();
	}
}

int main(int ac, char** av)
{
	assert(sizeof(void*) == sizeof(unsigned long));
	char a[]= "hello";
	char b[] = "coroutine";
	coroutine_new(co1, a);
	coroutine_new(co1, b);
	coroutine_main();
	return 0;
}