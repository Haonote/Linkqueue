#include<stdio.h>
#include<stdlib.h>
#include"Linkqueue.h"
int main()
{
	Linkqueue q;
	int a = 0;
	int b = 0;
	Initqueue(&q);
	printf("������Ҫ�����Ԫ�صĸ�����");
	scanf_s("%d", &a);
	for (int i = 0; i < a; i++)
	{
		Enqueue(&q);
	}
	for (int i = 0; i < a; i++)
	{
		b = Popqueue(&q);
		printf("%d   ", b);
	}
	printf("\n");
	return 0;
}