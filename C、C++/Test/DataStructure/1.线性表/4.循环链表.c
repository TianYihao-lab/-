#include<stdio.h>
#include<stdlib.h>

typedef int E;

typedef struct {
	E elemrnt;
	ListNode* next;
}ListNode,*Node;

void initList(Node node) {
	node->next = NULL;
}

