#include<stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int SElemType;

typedef int Status;

typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
} LinkStack;

Status InitStack(LinkStack *S)
{
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(!S->top)
        return ERROR;
    S->top = NULL;
    S->count = 0;
    return OK;
}

Status ClearStack(LinkStack *S)
{
    LinkStackPtr p,q;
    p = S->top;
    while(p)
    {
        q=p;
        p = p->next;
        free(q);
    }

    S->count = 0;
    return OK;
}

Status StackEmpty(LinkStack S)
{
    if(S.count == 0)
        return TRUE;
    else
        return FALSE;
}

int StackLength(LinkStack S)
{
    return S.count;
}

Status GetTop(LinkStack S,SElemType *e)
{
    if(S.top == NULL)
        return ERROR;
    else
        *e = S.top->data;
    
    return OK;
}

Status Push(LinkStack *S,SElemType e)
{
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;

    return OK;
}

Status Pop(LinkStack *S,SElemType *e)
{
    LinkStackPtr p;
    if(StackEmpty(*S))
        return ERROR;
    *e = S->top->data;

    p = S->top;

    S->top = S->top->next;

    free(p);

    S->count--;
    return OK;
}

Status StackTraverse(LinkStack S)
{
    LinkStackPtr p;
    p = S.top;
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }

    printf("\n");
    return OK;

}

int main(void)
{
    int j;
    LinkStack s;
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