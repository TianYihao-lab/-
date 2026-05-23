#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int E;
typedef struct LNode {
	E elment;
	struct LNode* next;
}LNode,*Node;
typedef struct Queue {
	Node front, rear;
}Queue,*LinkQueue;

bool initQueue(LinkQueue queue) {
	Node node = (Node)malloc(sizeof(LNode));
	if (node == NULL)return false;
	node->next = NULL;
	queue->front = queue->rear = node;
	return true;
}
bool push(LinkQueue queue,E e) {
	Node newnode = (Node)malloc(sizeof(LNode));
	if (newnode == NULL)return false;
	newnode->elment = e;
	newnode->next = NULL;
	queue->rear->next = newnode;
	queue->rear = newnode;
	return true;
}
E pop(LinkQueue queue) {
	E e = queue->front->next->elment;
	Node node = queue->front->next;
	queue->front->next = queue->front->next->next;  //直接让头结点指向下下个结点
	if (queue->rear == node) queue->rear = queue->front;   //如果队尾就是待出队的结点，那么队尾回到队首位置上
	free(node);   //释放内存
	return e;
}
bool isEmpty(Queue queue) {
	return queue.front == queue.rear;
}
int sizeQueue(Queue queue) {
	Node q = queue.front;
	int cnt = 0;
	while (q != queue.rear) {
		cnt++;
		q = q->next;
	}
	return cnt;
}
void printQueue(Queue* queue) {
	if (queue->front == queue->rear) {
		printf("<<< >>>");
		return;
	}
	printf("<<< ");
	Node node = queue->front->next;
	while (true) {    //注意不能直接判空，因为前面我们没考虑，也就没将新结点next设定为NULL
		printf("%d ", node->elment);
		if (node == queue->rear) break;    //当已经打印最后一个元素后，再结束
		else node = node->next;
	}
	printf(">>>\n");
}
void test01() {
	Queue queue;
	initQueue(&queue);
	for (int i = 0;i < 10;i++) {
		push(&queue, (i + 1) * 10);
	}
	printf("队列中的元素个数：%d\n", sizeQueue(queue));
	printQueue(&queue);
	while (!isEmpty(queue)) {
		printf("元素%d出队\n", pop(&queue));
	}
	printf("队列中的元素个数：%d\n", sizeQueue(queue));
	printQueue(&queue);
}

int main() {
	test01();
	return 0;
}