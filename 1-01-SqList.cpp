#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#include<stdio.h>

typedef int ElemType;


typedef struct 
{
	ElemType data[MAXSIZE];
	int length;
	
}SqList;


typedef int Status;

Status InitList(SqList *L)
{
	L->length = 0;
	return OK;
}

Status ListEmpty(SqList L)
{
	if(L.length == 0)
		return TRUE;
	else
		return FALSE;
}

Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}

/* GetElem */
Status GetElem(SqList L,int i,ElemType *e)
{
	if(L.length == 0 || i < 1 || i > L.length)
		return ERROR;
	*e = L.data[i - 1];
	return OK;
}


Status LocateElem(SqList L,ElemType e)
{
	int i;
	if(L.length == 0)
		return 0;
	for(i = 0; i<L.length;i++)
	{
		if(L.data[i] == e)
			break;
	}

	if(i>=L.length)
		return 0;
	
	return i+1;
}

Status ListInsert(SqList *L,int i,ElemType e)
{
	int k;
	if(L->length == MAXSIZE)
		return ERROR;

	if(i < 1 || i > L->length+1)
		return ERROR;

	if(i <= L->length)
	{
		for(k = L->length - 1; k >= i - 1; k--)
		{
			L->data[k + 1] = L->data[k];
		}		
	}

	L->data[i - 1] = e;
	L->length++;
	return OK;

}

Status ListDelete(SqList *L,int i,ElemType *e)
{
	int k;

	if(L->length == 0)
		return ERROR;

	if(i < 1 || i > L->length)
		return ERROR;

	*e = L->data[i - 1];

	if(i < L->length)
	{
		for(k = i;k<L->length;k++)
		{
			L->data[k - 1] = L->data[k];
		}
	}

	L->length--;
	return OK;
}

Status ListTraverse(SqList L)
{
	for(int i = 0;i< L.length;i++)
	{
		printf("%d ",L.data[i]);
	}
	printf("\n");

	return OK;
}

int main()
{
	SqList L;
	int result;
	int k;
	int testElem,testIndex;
	ElemType e;

	InitList(&L);
	printf("初始化L后: L.length=%d\n",L.length);

	for(int i=1;i <= 5;i++)
	{
		ListInsert(&L,1,i);
	}

	printf("在L的表头依次插入1~5后，L.data=");
	ListTraverse(L);
	printf("L.length=%d \n",L.length);

	result = ListEmpty(L);
	printf("L是否空：result=%d(1:是 0:否)\n",result);
	
	ClearList(&L);
	printf("清空L后：L.length=%d\n",L.length);
	
	result = ListEmpty(L);
	printf("L是否空：result=%d(1:是 0:否)\n",result);

	for(int i=1;i<= 10;i++)
	{
		ListInsert(&L,i,i);
	}

	printf("在L的表尾依次插入1～10后：L.data=");
	ListTraverse(L);

	printf("L.length=%d \n",L.length);
	
	ListInsert(&L,1,0);
	printf("在L的表头插入0后：L.data=");
	ListTraverse(L);
	printf("L.length=%d \n",L.length);
	GetElem(L,5,&e);
	printf("第5个元素的值为：%d\n",e);

	testElem = 9;
	k = LocateElem(L,testElem);
	if(k)
		printf("第%d个元素的值为%d\n",k,testElem);
	else
		printf("没有值为%d的元素\n",testElem);

	testElem = 100;
	k = LocateElem(L,testElem);
	if(k)
		printf("第%d个元素的值为%d\n",k,testElem);
	else
		printf("没有值为%d的元素\n",testElem);

	
	
	testIndex=5;
	ListDelete(&L,5,&e); /* 删除第5个数据 */
	printf("删除第%d个的元素值为：%d\n",testIndex,e);

	printf("依次输出L的元素：");
    ListTraverse(L); 
}