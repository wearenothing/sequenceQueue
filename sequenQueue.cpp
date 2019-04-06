// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
#define MAXSIZE 10
typedef int ElemType;
typedef struct Node* Queue;
struct Node
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
};

Queue creat()
{
	Queue q = (Queue)malloc(sizeof(struct Node));
	q->front = q->rear = -1;
	return q;
}
bool isEmpty(Queue q)
{
	return q->front == q->rear;
}
bool isFull(Queue q)
{
	return (q->rear + 1) % MAXSIZE ==q-> front;
}

void addQueue(Queue q, ElemType e)
{
	if (isFull(q))
	{
		printf("栈满\n");
		return;
	}
	q->rear = (q->rear + 1) % MAXSIZE;
	q->data[q->rear] = e;
}

ElemType deQueue(Queue q)
{
	if(isEmpty(q))
	{
		printf("栈空\n");
		return -1;
	}
	q->front = (q->front + 1) % MAXSIZE;
	return q->data[q->front];
}
int main()
{
    return 0;
}

