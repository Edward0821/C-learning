#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 50  //迷宫地图的最大高度（行数）
#define M 50  //迷宫地图的宽度（列数）
int flag = 0; //flag用来标记是否到达出口，为0表示未到达出口，为1表示已到达出口
int a[N][N];  //保存迷宫地图
int high;     //迷宫地图的高（行数）
int width;    //迷宫地图的宽（列数）
void Show(int a[][M], int high, int width);
int Go(int x, int y, int exitX, int exitY);
void ReadMazeFile(int a[][N], int *high, int *width);
int main(void)
{
    int x, y, exitX, exitY; //(x,y)为入口坐标，(exitX,exitY)为出口坐标
    ReadMazeFile(a, &high, &width);   //从文件中读取迷宫地图数据
    Show(a, high, width);             //显示high行width列的迷宫
    printf("Input x1,y1,x2,y2:");
    scanf("%d,%d,%d,%d", &x, &y, &exitX, &exitY); //输入起点和终点
    if (Go(x, y, exitX, exitY) == 0) //采用深度优先搜索和回溯法自动走迷宫
    {
        printf("没有路径！\n");
    }
    else
    {
        printf("恭喜走出迷宫！\n");
    }
    return 0;
}
//函数功能：从文件maze.txt中读取迷宫地图数据
void ReadMazeFile(int a[][M], int *high, int *width)
{
    FILE *fp = fopen("maze.txt", "r");
    if (fp == NULL)
    {
        printf("can not open the file\n");
        exit (0);
    }
    fscanf(fp, "%d%d", high, width);  //先从文件中读取迷宫地图的行数和列数
    for (int i=0; i<*high; i++)
    {
        for (int j=0; j<*width; j++)
        {
            fscanf(fp, "%d", &a[i][j]);
        }
    }
    fclose(fp);
}
//函数功能：显示high行width列的迷宫地图
void Show(int a[][M], int high, int width)
{
    for (int i=0; i<high; ++i)   //遍历n行
    {
        for (int j=0; j<width; ++j)//遍历m列
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
                printf("★");    //显示游戏玩家走过的位置
            }
        }
        printf("\n");
    }
}
//函数功能：采用深度优先搜索和回溯法自动走迷宫
int Go(int x, int y, int exitX, int exitY)
{
    a[x][y] = 2;               //走过的位置都标记为2，不可以再走
    system("cls");             //清屏
    Show(a, high, width);     //显示更新后的迷宫地图
    Sleep(200);                //延时200ms
    if (x == exitX && y == exitY) //到达迷宫出口位置exitX,exitY，则递归结束
    {
        flag = 1;
    }
    if (flag != 1 && a[x][y-1] == 0) //向左有路且未到达出口，则继续走
    {
        Go(x, y-1, exitX, exitY);
    }
    if (flag != 1 && a[x][y+1] == 0) //向右有路且未到达出口，则继续走
    {
        Go(x, y+1, exitX, exitY);
    }
    if (flag != 1 && a[x-1][y] == 0)//向上有路且未到达出口，则继续走
    {
        Go(x-1, y, exitX, exitY);
    }
    if (flag != 1 && a[x+1][y] == 0) //向下有路且未到达出口，则继续走
    {
        Go(x+1, y, exitX, exitY);
    }
    if (flag != 1)   //若以上四个方向均不可行，即无路可走，则回溯试探其他方向
    {
        a[x][y] = 0;//回溯，走过的位置恢复为空格
    }
    return flag;     //在主调函数中根据返回值判断是否走出迷宫
}
