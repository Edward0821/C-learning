//参考程序1
#include <stdio.h>
#define N 101
int NumberOff(int n, int m);
int main(void)
{
    int n, m, ret;
    do{
        printf("Input n,m(n>m):");
        ret = scanf("%d,%d", &n, &m);
        if (ret != 2) while (getchar()!='\n');
    }while (n<=m || n<=0 || m<=0 || ret!=2);
    printf("%d is left\n", NumberOff(n, m));
    return 0;
}
//函数功能：用整型数组求解循环报数问题
//函数参数：n为参与报数的总人数，每隔m人有一人退出圈子
//函数返回值：返回剩下的最后一个人的编号
int NumberOff(int n, int m)
{
    int i, c = 0, counter = 0, a[N];
    for (i=1; i<=n; ++i)         //按从1到n的顺序给每个人编号
    {
        a[i] = i;
    }
    do{
        for (i=1; i<=n; ++i)
        {
            if (a[i] != 0)
            {
                c++;               //元素不为0,则c加1,记录报数的人数
                if (c % m == 0)  //c除以m的余数为0,说明此位置为第m个报数的人
                {
                    a[i] = 0;      //将退出圈子的人的编号标记为0
                    counter++;     //记录退出的人数
                }
            }
        }
    }while (counter != n-1);//当退出圈子的人数达到n-1人时结束循环，否则继续循环
    for (i=1; i<=n; ++i)
    {
        if (a[i] != 0) return i;
    }
    return 0;
}

//参考程序2
#include <stdio.h>
#define N 101
typedef struct person 
{
    int number; //自己的编号
    int nextp;  //下一个人的编号
}LINK;  //用数组实现的静态循环链表
void CreatQueue(LINK link[], int n);
int NumberOff(LINK link[], int n, int m);
int main(void) 
{
    int n, m, last, ret;
    LINK link[N+1];
    do{
        printf("Input n,m(n>m):");
        ret = scanf("%d,%d", &n, &m);
        if (ret != 2) while (getchar()!='\n');
    }while (n<=m || n<=0 || m<=0 || ret!=2);
    CreatQueue(link, n);
    last = NumberOff(link, n, m);
    printf("%d is left\n", last);
    return 0;
}
//函数功能：用结构体数组求解循环报数问题
//函数参数：结构体数组link保存剩余的报数人的编号，n为参与报数的总人数
//          每隔m人有一人退出圈子，
//函数返回值：最后剩下的人的编号
int NumberOff(LINK link[], int n, int m) 
{
    int h = n, i, j, last;
for (j=1; j<n; ++j) 
{    
        i = 0;
        while (i != m) 
{       
            h = link[h].nextp;
            if (link[h].number != 0) ++i;
        }
        link[h].number = 0;
    }
for (i=1; i<=n; ++i) 
{    
        if (link[i].number != 0) last = link[i].number;
    }
    return last;
}
//函数功能：创建循环报数的队列
void CreatQueue(LINK link[], int n) 
{
    int i;
for (i=1; i<=n; ++i) 
{    
        if (i == n) link[i].nextp = 1;
        else          link[i].nextp = i + 1;
        link[i].number = i;
    }
}

//参考程序3
#include <stdio.h>
#include <stdlib.h>
typedef struct person 
{
    int num;
    struct person *next;
} LINK;
LINK *Create(int n);
int NumberOff(LINK *head, int n, int m);
void DeleteMemory(LINK *head);
int main(void) 
{
    LINK *head;
    int m, n, last, ret;
    do{
        printf("Input n,m(n>m):");
        ret = scanf("%d,%d", &n, &m);
        if (ret != 2) while (getchar()!='\n');
    }while (n<=m || n<=0 || m<=0 || ret!=2);
    head = Create(n);
    last = NumberOff(head, n, m);
    printf("%d is left\n", last);
    DeleteMemory(head, n);
    return 0;
}
//函数功能：用单向循环链表求解循环报数问题
//函数参数：指针head指向的链表保存剩余的报数人的编号，n为参与报数的总人数
//          每隔m人有一人退出圈子，
//函数返回值：最后剩下的人的编号
int NumberOff(LINK *head, int n, int m) 
{
    int i, j;
    LINK *p1 = head, *p2 = p1;
    if (n == 1 || m == 1)     return n;
for (i=1; i<n; ++i)  //将n-1个节点删掉
{   
        for (j=1; j<m-1; ++j) 
{       
            p1 = p1->next;
        }
        p2 = p1;        //p2指向第m个节点的前驱节点
        p1 = p1->next; //p1指向待删除的节点
        p1 = p1->next; //p1指向待删除节点的后继节点
        p2->next = p1;//让p1成为p2的后继节点，即循环删掉第m个节点
    }
    return p1->num;
}
//函数功能：创建报数的单向循环链表
LINK *Create(int n) 
{
    int i;
    LINK *p1, *p2, *head = NULL;
    p2 = p1 = (LINK*)malloc(sizeof(LINK));
if (p1 == NULL) 
{    
        printf("No enough memory to allocate!\n");
        exit(0);
    }
for (i=1; i<=n; ++i) 
{    
        if (i == 1) head = p1;
else          p2->next = p1;
p1->num = i;
        p2 = p1;
        p1 = (LINK*)malloc(sizeof(LINK));
        if (p1 == NULL) 
{       
            printf("No enough memory to allocate!\n");
            DeleteMemory(head);
            exit(0);
        }
    }
    free(p1);
    p2->next = head; //循环链表
    return head;
}
//函数功能：释放head指向的链表中所有节点占用的内存
void DeleteMemory(LINK *head) 
{
    LINK *p = head, *pr = NULL;
while (p != NULL) 
{    
        pr = p;
        p = p->next;
        free(pr);
    }
}
//参考程序4
#include <stdio.h>
#define  N  150
typedef struct queue 
{
    int number[N+1]; //编号
    int size;         //队列长度
    int head;         //队首
    int tail;         //队尾
} QUEUE;
void InitQueue(QUEUE *q, int n);
int EmptyQueue(const QUEUE *q);
int FullQueue(const QUEUE *q);
int DeQueue(QUEUE *q, int *e);
int EnQueue(QUEUE *q, int e);
int NumberOff(QUEUE *q, int n, int m);
int main(void) 
{
    int m, n, last;
    QUEUE q;
    printf("Input n,m(n>m):");
    scanf("%d,%d", &n, &m);
    InitQueue(&q, n);
    last = NumberOff(&q, n, m);
    printf("%d is left\n", last);
    return 0;
}
//函数功能：初始化循环队列
void InitQueue(QUEUE *q, int n) 
{
    q->size = n + 1;
    q->head = q->tail = 0;
}
//函数功能：判断循环队列是否为空
int EmptyQueue(const QUEUE *q) 
{
    if (q->head == q->tail) return 1;//队列为空        
    else return 0;
}
//函数功能：判断循环队列是否队满
int FullQueue(const QUEUE *q) 
{
    if ((q->tail + 1) % q->size == q->head) return 1; //队满        
    else   return 0;
}
//函数功能：循环队列进队
int EnQueue(QUEUE *q, int e) 
{
    if (FullQueue(q))  return 0;//队满
    q->number[q->tail] = e;
    q->tail = (q->tail + 1) % q->size; // 先移动指针，后放数据
    return 1;
}
//函数功能：循环队列出队，即删除队首元素
int DeQueue(QUEUE *q, int *e) 
{
    if (EmptyQueue(q)) return 0;
    *e = q->number[q->head];
    q->head = (q->head + 1) % q->size;  // 先移动指针，后放数据
    return 1;
}
//函数功能：循环报数
int NumberOff(QUEUE *q, int n, int m) 
{
    int i, j, e, num[N];
    for (i=0; i<n; i++) {     //将所有人编号并且排队    
        num[i] = i + 1;        //将所有人编号
        EnQueue(q, num[i]);	  //将每个人都入队
    }
    //排查报数为m的人
    i = j = 0;
while (!EmptyQueue(q)) 
{    
        i++;
        DeQueue(q, &e);
        if (i == m) 
{
            num[j] = e;
            i = 0;
            j++;
        }
        else
 {
            EnQueue(q, e);
        }        
    }    
    return num[n-1];
}
//参考程序5
#include<stdio.h>
#include<stdlib.h>
#define N 200
typedef struct QueueNode 
{
    int num;
    struct QueueNode *next;
} QueueNode;
typedef struct Queue 
{
    QueueNode *head;
    QueueNode *tail;
} QUEUE;
QUEUE *InitQueue() 
{
    QUEUE *q = (QUEUE *)malloc(sizeof(QUEUE));
if (q == NULL) //内存分配失败
{  
        printf("No enough memory to allocate!\n");
        exit(0);
    }
    q->head = q->tail = NULL;
    return q;
}
//函数功能：释放所有节点的内存
void DeleteMemory(QUEUE *q) 
{
    QueueNode *p;
while (q->head != q->tail) 
{
        p = q->head;
        q->head = q->head->next;
        free(p);
    }
    free(q->head);
}
//函数功能：循环队列入队
void EnQueue(QUEUE *q, int e) 
{
    QueueNode *p = (QueueNode *)malloc(sizeof(QueueNode));
if (p == NULL) //内存分配失败
{  
        printf("No enough memory to allocate!\n");
        DeleteMemory(q);
        exit(0);
    }
    p->num = e;
if (q->head == NULL) //空队列
{ 
        q->head = p;
        q->tail = p;
    }
else 
{
        q->tail->next = p;
        q->tail = p;
    }
    p->next = q->head;  //循环队列
}
//函数功能：循环队列出队，即删除队首元素
void DeQueue(QUEUE *q, int *e) 
{
    QueueNode *p = q->head;
    if (q->head == NULL) return;//空队列
    *e = q->head->num;
if (q->head == q->tail) //若队列中只剩一个节点
{   
        free(p);
        return;
    }
    q->head = q->head->next;
    q->tail->next = q->head;
    free(p);
}
//函数功能：循环报数
int NumberOff(QUEUE *q, int n, int m) 
{
    int i, j, e;
for (i=0; i<n; i++) 
{
        EnQueue(q, i+1);           //将所有人都编号入队
    }
    i = j = 0;
while (q->head != q->tail) //排查报数为m的人
{ 
        i++;                          //报数计数器
        if (i == m) 
{
            DeQueue(q, &e);	 //队首元素e出队
            i = 0;              //报数计数器重新开始计数
            j++;                 //出队数组下标
        }
        else 
{
            q->head = q->head->next;
            q->tail = q->tail->next;
        }
    }
    return q->head->num;    //返回最后剩下的那个人的编号
}
int main(void) 
{
    int m, n, last;
    printf("Input n,m(n>m):");
    scanf("%d,%d", &n, &m);
    QUEUE *q = InitQueue();
    last = NumberOff(q, n, m);
    printf("%d is left\n", last);
}
