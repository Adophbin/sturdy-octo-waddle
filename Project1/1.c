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

typedef struct {           /*定义结构体*/
	int* data;
	int length;
	int Maxsize;
}Sqlist;

Status InitList(Sqlist* L, int* n) {                      /*初始化顺序表*/
	L->data = (int*)malloc(*n * sizeof(int));
	L->length = 0;
	L->Maxsize = *n;
	return OK;
}

Status FillList(Sqlist* L, int* n) {                  /*填入数据*/
	int i;
	int* p = L->data;
	for (i = 0; i < *n; i++) {
		*p = i + 1;
		p += 1;
	}
	L->length = *n;
	return OK;
}

Status DeletElem(Sqlist* L, int i, int* e) {           /*删除顺序表中的i个元素，并取得其值*/
	if (i<1 || i>L->length)                            /*判断i值是否合法*/
		return ERROR;
	int j;
	*e = * (L->data + i - 1);                          /*将删除元素保存*/
	for (j = i; j <= L->length; j++) {                 /*被删除元素之后元素左移*/
		*(L->data + j - 1) = *(L->data + j);
	}
	L->length--;                                        
	return OK;
}

int main(void) {
	int a, b, c;
	int* n = &a, * m = &b, * e = &c;
	printf("请输入n和m！\n");
	scanf("%d,%d", &a, &b);
	if (a < b || a < 1 || b < 1)
		return ERROR;
	int count = 0, i = 1;
	Sqlist L;
	InitList(&L, n);
	FillList(&L, n);
	printf("输出顺序为：");
	while (count != *n) {							  /*计数器值为n时停止*/
		i = (i + *m - 1) % L.length;                  /*计算下一个元素位置*/
		if (i == 0)								      /*元素在表尾时*/
			i = L.length;
		DeletElem(&L, i, e);
		printf("%d ", c);
		count++;                                      /*计数器加一*/
	}
	return OK;
}