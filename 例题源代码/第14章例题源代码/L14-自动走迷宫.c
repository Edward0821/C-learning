#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define N 50  //迷宫地图的最大高度（行数）
#define M 50  //迷宫地图的宽度（列数）
int a[N][M];  //保存迷宫地图
int high;        //迷宫地图的行数(高度)
int width;       //迷宫地图的列数（宽度）
void ReadMazeFile(int a[][M], int *high, int *width);
void Show(int a[][M], int n, int m);
void UpdateWithInput(int a[][M], int x, int y, int exitX, int exitY);
int main(void)
{
    int x, y, exitX, exitY; //(x,y)为入口坐标，(exitX,exitY)为出口坐标
    ReadMazeFile(a, &high, &width);   //从文件中读取迷宫地图数据
    Show(a, high, width);             //显示high行width列的迷宫
    printf("Input x1,y1,x2,y2:");
    scanf("%d,%d,%d,%d", &x, &y, &exitX, &exitY); //输入起点和终点
    a[x][y] = 2;
    UpdateWithInput(a, x, y, exitX, exitY);  //与用户输入有关的更新
    return 0;
}
//函数功能：从maze.txt中读取迷宫地图数据
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
//函数功能：更新迷宫地图，若当前位置(x,y)已到达出口(exitX,exitY)，则玩家赢
void UpdateWithInput(int a[][M], int x, int y, int exitX, int exitY)
{
    char input;
    while (x != exitX || y != exitY)
    {
        system("cls");   //清屏
        Show(a, high, width);   //显示更新后的迷宫地图
        Sleep(200);      //延时200ms
        input = getch();
        if (input == 'a' && a[x][y-1] != 1) //左移
        {
            a[x][y] = 0;    //由2改成0
            a[x][--y] = 2;  //由0改成2
        }
        if (input == 'd' && a[x][y+1] != 1) //右移
        {
            a[x][y] = 0;
            a[x][++y] = 2;
        }
        if (input == 'w' && a[x-1][y] != 1) //上移
        {
            a[x][y] = 0;
            a[--x][y] = 2;
        }
        if (input == 's' && a[x+1][y] != 1) //下移
        {
            a[x][y] = 0;
            a[++x][y] = 2;
        }
    }
    system("cls");   //清屏
    Show(a, high, width);   //显示更新后的迷宫地图
    Sleep(200);      //延时200ms
    printf("You win!\n");
}
