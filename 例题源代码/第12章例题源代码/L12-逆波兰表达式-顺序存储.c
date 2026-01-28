#include <stdio.h>
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
   NodeType data[N];
   int top;   //控制栈顶
}STACK;       //栈的顺序存储
void Push(STACK *stack, NodeType data);
NodeType Pop(STACK *stack);
NodeType OpInt(int d1, int d2, int op);
NodeType OpData(NodeType *d1, NodeType *d2, int op);
int main(void)
{
    char word[N];
    NodeType d1, d2, d3;
    STACK stack;
    stack.top = 0;//初始化栈顶
    //以空格为分隔符输入逆波兰表达式，以#结束
    while (scanf("%s", word) == 1 && word[0] != '#')
    {
        if (isdigit(word[0])) //若为数字，则转换为整型后压栈
        {
            d1.ival = atoi(word);//将word转换为整型数据
            Push(&stack, d1);
        }
        else  //否则弹出两个操作数，执行相应运算后再将结果压栈
        {
            d2 = Pop(&stack);
            d1 = Pop(&stack);
            d3 = OpData(&d1, &d2, word[0]);
            Push(&stack, d3);
        }
    }
    d1 = Pop(&stack);  //弹出栈顶保存的最终计算结果
    printf("%d\n", d1.ival);
    return 0;
}
//函数功能：将数据data压入堆栈
void Push(STACK *stack, NodeType data)
{
    memcpy(&stack->data[stack->top], &data, sizeof(NodeType));
    stack->top = stack->top + 1;
}
//函数功能：弹出栈顶数据并返回
NodeType Pop(STACK *stack)
{
    stack->top = stack->top - 1;
    return stack->data[stack->top];
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
