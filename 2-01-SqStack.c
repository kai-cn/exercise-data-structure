#include<stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int SElemType;

typedef int Status;

typedef struct
{
    SElemType data[MAXSIZE];
    int top;
}SqStack;

Status InitStack(SqStack *S)
{
    S->top = -1;
    return OK;
}

Status ClearStack(SqStack *S)
{
    S->top = -1;
    return OK;
}

Status StackEmpty(SqStack s)
{
    if(s.top == -1)
        return TRUE;
    else
        return FALSE;
}

int StackLength(SqStack S)
{
    return S.top+1;
}

Status GetTop(SqStack S,SElemType *e)
{
    if(S.top == -1)
        return ERROR;
    else
        *e = S.data[S.top];
    return OK;
}

Status Push(SqStack *S,SElemType e)
{
    if(S->top == MAXSIZE - 1)
    {
        return ERROR;
    }

    S->top++;

    S->data[S->top] = e;
    
    return OK;
}

Status Pop(SqStack *S,SElemType *e)
{
    if(S->top == -1)
    {
        return ERROR;
    }

    *e = S->data[S->top];

    S->top--;

    return OK;
}

Status StackTraverse(SqStack S)
{
    int i;
    i = 0;
    while(i<= S.top)
    {
        printf("%d ",S.data[i++]);
    }
    printf("\n");
    return OK;
}

int main(void)
{
    int j;
    SqStack s;
    int e;
    if(InitStack(&s)==OK)
            for(j=1;j<=10;j++)
                    Push(&s,j);
    printf("栈中元素依次为：");
    StackTraverse(s);

    Pop(&s,&e);
    printf("弹出的栈顶元素 e=%d\n",e);
    printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));

    GetTop(s,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
    
    return 0;
}
