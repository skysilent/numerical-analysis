#include"coroutine.h"

#include <memory>
#include <setjmp.h>
#include <assert.h>

// stack size 2M
#define CORO_STACK_SIZE 1024 * 1024 * 2

#define CORO_FUN_INIT 0
#define CORO_FUN_END 1
#define CORO_FUN_YIELD 2

struct coroutine;

static struct coroutine* current_coro = NULL;
static struct coroutine* coro_list = NULL;
static int coro_num = 0;

jmp_buf main_env;

struct coroutine
{
	struct coroutine *prev, *next;

	int co_id;
	coroutine_function co_fun;
	void* co_arg;
	void* co_stack;

	jmp_buf co_env;
};

static void _start_coro()
{
	current_coro->co_fun(current_coro->co_arg);
	longjmp(main_env, CORO_FUN_END);
}

void coroutine_new(coroutine_function f, void* arg)
{
	struct coroutine* co = (struct coroutine*) malloc(sizeof(struct coroutine));
	assert(co);

	if (coro_list)
	{
		co->prev = coro_list->prev;
		co->next = coro_list;
		coro_list->prev->next = co;
		coro_list->prev = co;
	}
	else
	{
		co->prev = co;
		co->next = co;
	}
	coro_list = co;

	// init struct Coro
	co->co_id = ++coro_num;
	co->co_fun = f;
	co->co_arg = arg;
	co->co_stack = malloc(CORO_STACK_SIZE);
	assert(co->co_stack);

	// init jmp buf
	setjmp(co->co_env);
	_JUMP_BUFFER* jmp_buf = (_JUMP_BUFFER*)&(co->co_env);

	jmp_buf->Eip = (unsigned long)(_start_coro);
	jmp_buf->Esp = (unsigned long)((char*)(co->co_stack) + CORO_STACK_SIZE - 16);
}

void coroutine_main()
{
	if (!coro_list)
		return;

	struct coroutine *co;
	switch (setjmp(main_env))
	{
	case CORO_FUN_INIT:
		// scheduling
		current_coro = coro_list;
		break;

	case CORO_FUN_END:
		co = current_coro;
		if (co->next == co)
		{
			coro_list = NULL;
			free(co->co_stack);
			free(co);
			return;
		}
		// scheduling
		current_coro = current_coro->next;
		co->prev->next = co->next;
		co->next->prev = co->prev;
		free(co->co_stack);
		free(co);
		break;

	case CORO_FUN_YIELD:
		// scheduling
		current_coro = current_coro->next;
	}
	assert(current_coro);
	longjmp(current_coro->co_env, 1);
}

void coroutine_yield()
{
	if (setjmp(current_coro->co_env))
		return;
	longjmp(main_env, CORO_FUN_YIELD);
}