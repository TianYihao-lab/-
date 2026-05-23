#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int E;
typedef struct Queue {
    E* array;
    int capacity;
    int front, rear;
}Queue, *ArrayQueue;

bool initQueue(ArrayQueue queue) {
    queue->capacity = 20;
    queue->front = queue->rear = -1;
    queue->array = (E*)malloc(sizeof(E) * 20);
    if (queue->array == NULL) return false;
    return true;
}

bool push(ArrayQueue queue, E e) {
    if ((queue->rear + 1) % queue->capacity == queue->front) return false;
    int temp = (queue->rear + 1) % queue->capacity;     // 容量为n的队列，其元素下标的范围是[0,n-1]
    queue->array[temp] = e;
    queue->rear = temp;
    return true;
}

bool isEmpty(ArrayQueue queue) {
    return queue->front == queue->rear;
}

E pop(ArrayQueue queue) {
    if (isEmpty(queue)) return -1;
    queue->front = (queue->front + 1) % queue->capacity;
    return queue->array[queue->front];
}

int sizeQueue(Queue queue) {
    return (queue.rear - queue.front + queue.capacity) % queue.capacity;
}

void printQueue(Queue queue) {
    for (int i = (queue.front + 1) % queue.capacity; i != (queue.rear + 1) % queue.capacity; i = (i + 1) % queue.capacity) {
        printf("%d ", queue.array[i]);
    }
    puts("");
}

void test01() {
    Queue queue;
    initQueue(&queue);
    isEmpty(&queue)? printf("队列暂时为空\n") : printf("队列不为空\n");
    puts("");
    for (int i = 0; i < 10; i++) {
        push(&queue, (i + 1) * 10);
    }
    isEmpty(&queue)? printf("队列暂时为空\n") : printf("队列不为空\n");
    printf("队列中的元素个数为：%d\n", sizeQueue(queue));
    printQueue(queue);
    puts("");
    while (!isEmpty(&queue)) {
        printf("元素%d出队\n", pop(&queue));
    }
    isEmpty(&queue)? printf("队列暂时为空\n") : printf("队列不为空\n");
    printf("队列中的元素个数为：%d\n", sizeQueue(queue));
    printQueue(queue);
}
void test02() {
    Queue queue;
    initQueue(&queue);
    isEmpty(&queue) ? printf("队列暂时为空\n") : printf("队列不为空\n");
    puts("");
    for (int i = 0; i < 20; i++) {              // 为了区分 `队空` 和 `队满`,有一个存放元素的空间被浪费了 
        push(&queue, (i + 1) * 10);
    }
    isEmpty(&queue) ? printf("队列暂时为空\n") : printf("队列不为空\n");
    printf("队列中的元素个数为：%d\n", sizeQueue(queue));
    printQueue(queue);
}
int main() {
   test01();
   // test02();
    return 0;
}