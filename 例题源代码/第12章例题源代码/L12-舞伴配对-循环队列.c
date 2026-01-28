#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
typedef struct queue
{
    char elem[N][N];
    int  qSize;  //队列长度
    int  front;  //控制对头
    int  rear;   //控制队尾
}QUEUE;
void CreatQueue(QUEUE *Q);
int QueueEmpty(const QUEUE *Q);
void DeQueue(QUEUE *Q, char *str);
void GetQueue(const QUEUE *Q, char *str);
void DancePartners(QUEUE *man, QUEUE *women);
void Match(QUEUE *shortQ, QUEUE *longQ);

int main(void)
{
    QUEUE man, women;
    printf("男队：\n");
    CreatQueue(&man);
    printf("女队：\n");
    CreatQueue(&women);
    DancePartners(&man, &women);
    return 0;
}
//函数功能：创建一个队列
void CreatQueue(QUEUE *Q)
{
    int n, i;
    Q->front = Q->rear = 0;
    printf("请输入跳舞人数：");
    scanf("%d", &n);
    Q->qSize = n + 1;
    printf("请输入各舞者人名：");
    for (i=0; i<n; i++)
    {
        scanf("%s", Q->elem[i]);
    }
    Q->rear = n;
}
//函数功能：判断循环队列是否为空
int QueueEmpty(const QUEUE *Q)
{
    if (Q->front == Q->rear)//循环队列为空
        return 1;
    else
        return 0;
}
//函数功能：循环队列出队，即删除队首元素
void DeQueue(QUEUE *Q, char *str)
{
    strcpy(str, Q->elem[Q->front]);
    Q->front = (Q->front + 1) % Q->qSize;
}
//函数功能：取出队首元素，队头指针不改变
void GetQueue(const QUEUE *Q, char *str)
{
    strcpy(str, Q->elem[Q->front]);
}
//函数功能：根据队列长短确定如何调用舞伴配对函数
void DancePartners(QUEUE *man, QUEUE *women)
{
    if (man->qSize < women->qSize)
    {
        Match(man, women);
    }
    else
    {
        Match(women, man);
    }
}
//函数功能：舞伴配对
void Match(QUEUE *shortQ, QUEUE *longQ)
{
    int n;
    char str1[N], str2[N];
    printf("请输入舞会的轮数：");
    scanf("%d", &n);
    while (n--) //循环n轮次
    {
        while (!QueueEmpty(shortQ)) //短队列不为空
        {
            if (QueueEmpty(longQ))
            {
                longQ->front = (longQ->front + 1) % longQ->qSize;
            }
            DeQueue(shortQ, str1);
            DeQueue(longQ, str2);
            printf("配对的舞者：%s %s\n", str1, str2);
        }
        shortQ->front = (shortQ->front + 1) % shortQ->qSize;
        if (QueueEmpty(longQ))
        {
            longQ->front = (longQ->front + 1) % longQ->qSize;
        }
        GetQueue(longQ, str1);
        printf("第一个出场的未配对者的姓名：%s\n", str1);
    }
}
