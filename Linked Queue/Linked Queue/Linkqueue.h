#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef struct Qnode {
	int a;
	struct Qnode* next;
}Qnode,*Queueptr;
typedef struct {
	Queueptr front;
	Queueptr rear;
}Linkqueue;
int Initqueue(Linkqueue* q)
{
	q->front =  (Queueptr)malloc(sizeof(Qnode));
	q->rear = q->front;
	if (!q->front) exit(OVERFLOW);
	q->front->next = NULL;
	return 0;
}
int Destoryqueue(Linkqueue* q)
{
	while (q->front)
	{
		Queueptr p;
		p = q->front->next;
		free(q->front);
		q->front = p;//移动指针指向删除节点的后继节点
	}//可以用尾指针代替p
	return OK;
}
int Enqueue(Linkqueue* q)
{
	int e = 0;
	Queueptr p = (Queueptr)malloc(sizeof(Qnode));
	if (!p) exit(OVERFLOW);
	printf("请输入要加入的元素:");
	scanf_s("%d", &e);
	p->a = e;
	p->next = NULL;
	q->rear->next = p;//添加后继节点
	q->rear = p;//更改尾指针
	return OK;
}
int Popqueue(Linkqueue* q)
{
	if (q->front == q->rear) return ERROR;
	int e = 0;
	Queueptr p = (Queueptr)malloc(sizeof(Qnode));
	p = q->front->next;
	e = p->a;//要返回的值
	q->front->next = p->next;//头节点指向未删除前首元素的后继
	if (q->rear == p) q->rear = q->front;//特殊情况，只有一个元素删除后为空
	free(p);
	return e;
}
int GetHead(Linkqueue q)
{
	if (q.front == q.rear) return ERROR;
	int e = 0;
	e = q.front->next->a;
	return e;
}