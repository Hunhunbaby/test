#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct LNode
{
    char data;
    LNode *lchild,*rchild;
}LNode;

typedef struct
{
    int elements[40];
    int top;
}stack;

typedef struct Link
{
    int data[100];
    int number;
}Link;

void push(stack *s,int e)
{
    s->top++;
    s->elements[s->top]=e;
}

int pop(stack *s)
{
    int temp;
    s->top--;
    temp=s->elements[s->top+1];
    return temp;
}

void SetNull(stack *&s)
{
    s=(stack*)malloc(sizeof(stack));
    s->top=-1;
}

void CreateBiTree(Link *&T)
{
    int n;
    T->number=0;
    for(int i=0;i<=5;i++)
    {
        scanf("%d",&n);
        T->data[T->number]=n;
        T->number++;
    }

}

void Show(Link *T,stack *s)
{
    int i=1;
    int n;
    push(s,T->data[i]);
    while(s->top!=-1)
    {
        n=pop(s);
        printf("%d ",n);
        if(2*n>T->number-1)
        {
            continue;
        }
        if(2*n+1 >= T->number)
        {
            push(s,T->data[2*n]);
            continue;
        }
        push(s,T->data[2*n+1]);
        push(s,T->data[2*n]);
    }
}

int main()
{
    while(1)
    {
        stack *s;
        Link *T;
        T=(Link *)malloc(sizeof(Link));
        CreateBiTree(T);
        SetNull(s);
        Show(T,s);
        system("pause");
        system("CLS");
        return 0;
    }

}

