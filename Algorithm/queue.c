#include <stdio.h>

#define max 100

typedef struct{
	int buf[max];
	int front;
	int rear;
}Queue;

Queue queue;

void initQueue(){
	queue.front = -1;
	queue.rear = -1;
}

void push(int n){
	queue.buf[++queue.rear%max]=n;
}

int pop(){
	return queue.buf[++queue.front%max];
}
