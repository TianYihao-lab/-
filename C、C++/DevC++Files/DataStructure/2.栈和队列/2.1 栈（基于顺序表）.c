#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 基于顺序表实现一个栈

typedef int E;

typedef struct
{
	E *array;
	int capacity;
	int top; // top的值表示当前存放到第几个位置了跟数组下表保持一致，范围是[0,capacity-1]
} Stack, *ArrayStack;

bool initStack(ArrayStack stack)
{
	stack->array = (E *)malloc(sizeof(E) * 10);
	if (stack->array == NULL)
		return false;
	stack->capacity = 10;
	stack->top = -1;
	return true;
}

bool push(ArrayStack stack, E e)
{
	if (stack->top + 1 == stack->capacity)
		return false;
	stack->array[++stack->top] = e;
	return true;
}

int pop(ArrayStack stack)
{
	if (stack->top < 0)
		return;
	return stack->array[stack->top--];
}

void printArray(ArrayStack stack)
{
	for (int i = 0; i < stack->top + 1; i++)
	{
		printf("%d ", stack->array[i]);
	}
	puts("");
}

int sizeArray(ArrayStack stack)
{
	return stack->top + 1;
}

int main()
{
	Stack stack;
	initStack(&stack);
	for (int i = 0; i < 10; i++)
	{
		push(&stack, i + 1);
	}
	printf("栈中有%d个元素\n", sizeArray(&stack));
	printArray(&stack);
	for (int i = 0; i < 10; i++)
		printf("弹出元素：%d\n", pop(&stack));
	puts("");
	printf("弹出元素后，栈中有%d个元素\n", sizeArray(&stack));
	return 0;
}