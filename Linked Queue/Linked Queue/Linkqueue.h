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
		q->front = p;//�ƶ�ָ��ָ��ɾ���ڵ�ĺ�̽ڵ�
	}//������βָ�����p
	return OK;
}
int Enqueue(Linkqueue* q)
{
	int e = 0;
	Queueptr p = (Queueptr)malloc(sizeof(Qnode));
	if (!p) exit(OVERFLOW);
	printf("������Ҫ�����Ԫ��:");
	scanf_s("%d", &e);
	p->a = e;
	p->next = NULL;
	q->rear->next = p;//��Ӻ�̽ڵ�
	q->rear = p;//����βָ��
	return OK;
}
int Popqueue(Linkqueue* q)
{
	if (q->front == q->rear) return ERROR;
	int e = 0;
	Queueptr p = (Queueptr)malloc(sizeof(Qnode));
	p = q->front->next;
	e = p->a;//Ҫ���ص�ֵ
	q->front->next = p->next;//ͷ�ڵ�ָ��δɾ��ǰ��Ԫ�صĺ��
	if (q->rear == p) q->rear = q->front;//���������ֻ��һ��Ԫ��ɾ����Ϊ��
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