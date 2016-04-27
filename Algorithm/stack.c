#include <stdio.h>

#define MAX 100

typedef struct{
	int buf[MAX];
	int top;
}Stack;

void initStack(Stack *stack){
	stack->top = -1;
}

void push(Stack *stack,int data){
	stack->buf[++stack->top]=data;
}

int pop(Stack *stack){
	return stack->buf[stack->top--];
}
