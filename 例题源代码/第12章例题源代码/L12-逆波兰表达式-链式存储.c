#include  <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define INT 1
#define FLT 2
#define N 20
typedef struct node
{
    int ival;
}NodeType;
typedef struct stack
{
   NodeType data;
   struct stack *next;  //指向栈顶
}STACK;                   //栈的链式存储
STACK *Push(STACK *top, NodeType data);
STACK *Pop(STACK *top);
NodeType OpInt(int d1, int d2, int op);
NodeType OpData(NodeType *d1, NodeType *d2, int op);
int main(void)
{
    char word[N];
    NodeType d1, d2, d3;
    STACK *top = NULL;//初始化栈顶
    //以空格为分隔符输入逆波兰表达式，以#结束
    while (scanf("%s", word) == 1 && word[0] != '#')
    {
        if (isdigit(word[0])) //若为数字，则转换为整型后压栈
        {
            d1.ival = atoi(word);//将word转换为整型数据
            top = Push(top, d1);
        }
        else  //否则弹出两个操作数，执行相应运算后再将结果压栈
        {
            d2 = top->data;
            top = Pop(top);
            d1 = top->data;
            top = Pop(top);
            d3 = OpData(&d1, &d2, word[0]);
            top = Push(top, d3);
        }
    }
    d1 = top->data;
    printf("%d\n", d1.ival);
    top = Pop(top);  //弹出栈顶保存的最终计算结果
    return 0;
}
//函数功能：将数据data压入堆栈
STACK *Push(STACK *top, NodeType data)
{
    STACK *p;
    p = (STACK *)malloc(sizeof(STACK));
    p->data = data;
    p->next = top;
    top = p;
    return top;
}
//函数功能：弹出栈顶数据并返回
STACK *Pop(STACK *top)
{
    STACK *p;
    if (top == NULL)
    {
        return NULL;
    }
    else
    {
        p = top;
        top = top->next;
        free(p);  //注意弹出栈顶数据后要释放其所占用的内存
    }
    return top;
}
//函数功能：对整型的数据d1和d2执行运算op，并返回计算结果
NodeType OpInt(int d1, int d2, int op)
{
    NodeType res;
    switch (op)
    {
    case '+':
        res.ival = d1 + d2;
        break;
    case '-':
        res.ival = d1 - d2;
        break;
    case '*':
        res.ival = d1 * d2;
        break;
    case '/':
        res.ival = d1 / d2;
        break;
    }
    return res;
}
//函数功能：对d1和d2执行运算op，并返回计算结果
NodeType OpData(NodeType *d1, NodeType *d2, int op)
{
    NodeType res;
    res = OpInt(d1->ival, d2->ival, op);
    return res;
}
