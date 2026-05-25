#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 基于顺序表实现一个共享栈

typedef int E;

typedef struct
{
	E *array;
	int capacity;
	int ltop;
	int rtop;
} Stack, *ArrayStack;

bool initStack(ArrayStack stack)
{
	stack->array = (E *)malloc(sizeof(E) * 10);
	if (stack->array == NULL)
		return false;
	stack->capacity = 10;
	stack->ltop = -1;
	stack->rtop = stack->capacity;
	return true;
}
bool lpushStack(ArrayStack stack, E e)
{
	if (stack->ltop + 1 == stack->rtop)
		return false;

	stack->array[++stack->ltop] = e;
	return true;
}
bool rpushStack(ArrayStack stack, E e)
{
	if (stack->ltop + 1 == stack->rtop)
		return false;

	stack->array[--stack->rtop] = e;
	return true;
}
int lpopStack(ArrayStack stack)
{
	if (stack->ltop == -1)
		return;

	return stack->array[stack->ltop--];
}
int rpopStack(ArrayStack stack)
{
	if (stack->rtop == stack->capacity)
		return;

	return stack->array[stack->rtop++];
}
int lsizeStack(ArrayStack stack)
{
	return stack->ltop + 1;
}
int rsizeStack(ArrayStack stack)
{
	return stack->capacity - stack->rtop;
}
int sizeStack(ArrayStack stack)
{
	return stack->capacity - (stack->rtop - stack->ltop - 1);
}
int main()
{
	Stack stack;
	initStack(&stack);
	for (int i = 0; i < 3; ++i)
	{
		printf("元素%d进栈\n", i + 1);
		lpushStack(&stack, i + 1);
	}
	for (int i = 3; i > 0; i--)
	{
		printf("元素%d进栈\n", i);
		rpushStack(&stack, i);
	}
	for (int j = 0; j < 3; j++)
	{
		printf("弹出元素：%d\n", lpopStack(&stack));
		printf("左栈中元素个数为：%d 右栈中元素个数为：%d 栈中总元素个数为：%d\n", lsizeStack(&stack), rsizeStack(&stack), sizeStack(&stack));
	}
	puts("");
	for (int j = 0; j < 3; j++)
	{
		printf("弹出元素：%d\n", rpopStack(&stack));
		printf("左栈中元素个数为：%d 右栈中元素个数为：%d 栈中总元素个数为：%d\n", lsizeStack(&stack), rsizeStack(&stack), sizeStack(&stack));
	}

	return 0;
}