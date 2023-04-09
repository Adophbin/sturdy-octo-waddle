#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

typedef struct {           /*����ṹ��*/
	int* data;
	int length;
	int Maxsize;
}Sqlist;

Status InitList(Sqlist* L, int* n) {                      /*��ʼ��˳���*/
	L->data = (int*)malloc(*n * sizeof(int));
	L->length = 0;
	L->Maxsize = *n;
	return OK;
}

Status FillList(Sqlist* L, int* n) {                  /*��������*/
	int i;
	int* p = L->data;
	for (i = 0; i < *n; i++) {
		*p = i + 1;
		p += 1;
	}
	L->length = *n;
	return OK;
}

Status DeletElem(Sqlist* L, int i, int* e) {           /*ɾ��˳����е�i��Ԫ�أ���ȡ����ֵ*/
	if (i<1 || i>L->length)                            /*�ж�iֵ�Ƿ�Ϸ�*/
		return ERROR;
	int j;
	*e = * (L->data + i - 1);                          /*��ɾ��Ԫ�ر���*/
	for (j = i; j <= L->length; j++) {                 /*��ɾ��Ԫ��֮��Ԫ������*/
		*(L->data + j - 1) = *(L->data + j);
	}
	L->length--;                                        
	return OK;
}

int main(void) {
	int a, b, c;
	int* n = &a, * m = &b, * e = &c;
	printf("������n��m��\n");
	scanf("%d,%d", &a, &b);
	if (a < b || a < 1 || b < 1)
		return ERROR;
	int count = 0, i = 1;
	Sqlist L;
	InitList(&L, n);
	FillList(&L, n);
	printf("���˳��Ϊ��");
	while (count != *n) {							  /*������ֵΪnʱֹͣ*/
		i = (i + *m - 1) % L.length;                  /*������һ��Ԫ��λ��*/
		if (i == 0)								      /*Ԫ���ڱ�βʱ*/
			i = L.length;
		DeletElem(&L, i, e);
		printf("%d ", c);
		count++;                                      /*��������һ*/
	}
	return OK;
}