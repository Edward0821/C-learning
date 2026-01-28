#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define NO 120
#define SIZE 20
typedef struct
{
    char name[SIZE];
    short flag;
}LUCKY;
int ReadFromFile(char fileName[], LUCKY msg[]);
void PrizeDraw(LUCKY msg[], int total, int prizesNum);
int main(void)
{
    LUCKY msg[NO];
    char fileName[SIZE];
    printf("请输入抽奖者信息文件名:");
    scanf("%s", fileName);
    int total = ReadFromFile(fileName, msg);
    printf("总计%d名学生\n", total);
    int prizesNum;
    do {
        printf("请输入奖品数量：");
        scanf("%d", &prizesNum);
    }while (prizesNum > total);
    PrizeDraw(msg, total, prizesNum);
    return 0;
}
int ReadFromFile(char fileName[], LUCKY msg[])
{
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("can not open file %s\n", fileName);
        return 1;
    }
    int i = 0;
    while (fgets(msg[i].name, sizeof(msg[i].name), fp))
    {
        i++;
    }
    fclose(fp);
    return i;
}
void PrizeDraw(LUCKY msg[], int total, int prizesNum)
{
    for (int i=0; i<total; i++)
    {
       msg[i].flag = 0;//标记都没有被抽过
    }
    int i = 0;
    int j = 0;
    int k;
    while (j != prizesNum) //奖品尚未抽完，则继续循环
    {
        k = i % total;      //确保循环显示抽奖者信息
        if (kbhit() && msg[k].flag == 0)//当有按键，并且第k个人也没有被抽过
        {
            j++;           //计数器记录已中奖人数
            system("cls"); //清屏
            printf("恭喜第%d位中奖者:%s", j, msg[k].name);
            msg[k].flag = 1;//标记其已经被抽过
            system("pause");//等待用户按任意键，以回车符结束输入
        }
        else
        {
            printf("%s", msg[k].name); //若没有检测到按键，则循环显示抽奖者信息
        }
        i++;
    }
    printf("抽奖完毕！\n");
}
