#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define NO 120
#define SIZE 20
int ReadFromFile(char fileName[], char msg[][SIZE]);
void PrizeDraw(char msg[][SIZE], int total);
int main(void)
{
    char msg[NO][SIZE];
    char fileName[SIZE];
    printf("请输入抽奖者信息文件名:");
    scanf("%s", fileName);
    int total = ReadFromFile(fileName, msg);
    printf("总计%d名学生\n", total);
    PrizeDraw(msg, total);
    return 0;
}
//函数功能：从文件fileName中读取抽奖者的信息msg，返回抽奖者人数
int ReadFromFile(char fileName[], char msg[][SIZE])
{
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("can not open file %s\n", fileName);
        return 1;
    }
    int i = 0;
    while (fgets(msg[i], sizeof(msg[i]), fp))
    {
        i++;
    }
    fclose(fp);
    return i;
}
//函数功能：从total个人的信息msg中循环抽取幸运者
void PrizeDraw(char msg[][SIZE], int total)
{
    int i = 0;
    int k;
    while (1) //循环抽奖
    {
        k = i % total;      //确保循环显示抽奖者信息
        if (kbhit())        //当有按键，表示抽中了一位幸运者
        {
            system("cls"); //清屏
            printf("恭喜:%s", msg[k]);
            system("pause");//等待用户按任意键，以回车符结束输入
        }
        else
        {
            printf("%s", msg[k]); //若没有检测到按键，则循环显示抽奖者信息
        }
        i++;
    }
}
