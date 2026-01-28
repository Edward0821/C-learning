#include <stdio.h>
#include <stdlib.h>
#define N 50
#define M 50
int a[N][M];
void ReadMazeFile(int a[][M], int *n, int *m);
void Show(int a[][M], int n, int m);
int main(void)
{
    int n, m;
    ReadMazeFile(a, &n, &m);  //读取迷宫地图
    Show(a, n, m);              //显示初始迷宫
    return 0;
}
//函数功能：从maze.txt中读取迷宫地图
void ReadMazeFile(int a[][M], int *n, int *m)
{
    FILE *fp = fopen("maze.txt", "r");//以只读方式打开文件
    if (fp == NULL) //如果文件打开不成功
    {
        printf("can not open the file\n");
        exit(0);
    }
    fscanf(fp, "%d%d", n, m);    //读迷宫大小
    for (int i=0; i<*n; i++)      //遍历所有行 
    {
        for (int j=0; j<*m; j++)  //遍历所有列
        {
            fscanf(fp, "%d", &a[i][j]); //读迷宫数据
        }
    }
    fclose(fp); //关闭文件
}
//函数功能：显示n*m大小的迷宫地图
void Show(int a[][M], int n, int m)
{
    for (int i=0; i<n; ++i)   //遍历n行
    {
       for (int j=0; j<m; ++j)//遍历m列
       {
            if (a[i][j] == 0)
            {
                printf("  ");   //显示路
            }
            else if (a[i][j] == 1)
            {
                printf("■");    //显示墙
            }
            else if (a[i][j] == 2)
            {
                printf("★");    //显示游戏玩家
            }
       }
       printf("\n");
    }
}
