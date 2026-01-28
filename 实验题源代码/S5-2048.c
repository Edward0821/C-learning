#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define N 2048
#define M 10
void Menu(void);
void CreateNumber(int a[4][4]);
void UserInput(int a[4][4]);
void Judge(int a[4][4]);
void Show(int a[4][4]);
int MoveUp(int a[4][4]);
int MoveDown(int a[4][4]);
int MoveLeft(int a[4][4]);
int MoveRight(int a[4][4]);
//主函数
int main(void)
{
    int a[4][4] = {0};
    Menu();
    while (1)
    {
        Judge(a);
        CreateNumber(a);
        Show(a);
        UserInput(a);
        system("CLS");
        Show(a);
        Sleep(500);
        system("CLS");
    }
    printf("退出成功，欢迎再次使用！");
    return 0;
}
//函数功能：显示菜单
void Menu(void)
{
    system("color F0");
    system("mode con cols=40 lines=20");
    printf("欢迎来到2048！\n");
    printf("游戏规则：a：向左划\n");
    printf("          d：向右划\n");
    printf("          w：向上划\n");
    printf("          s：向下滑\n");
    printf("          0：退出游戏\n");
    printf("请点击任意键进入游戏\n");
    system("PAUSE");
    system("CLS");
}
//函数功能：生成新的数字
void CreateNumber(int a[4][4])
{
    int i, j, n;
    srand ((unsigned)time(NULL));
    n = 0;
    do{
            i = rand() % 4;
            j = rand() % 4;
            if (a[i][j] == 0)
            {
                a[i][j] = 2;
                n++;
            }
    }while (n < 2);

}
//函数功能：根据用户键盘输入变化相应的操作
void UserInput(int a[4][4])
{
    int n;
    char flag;
    do{
        flag = getch();
        switch (flag)
        {
        case 'w':
            n = MoveUp(a);
            break;
        case 's':
            n = MoveDown(a);
            break;
        case 'a':
            n = MoveLeft(a);
            break;
        case 'd':
            n = MoveRight(a);
            break;
        case '0':
            n = 1;
            break;
        default :
            printf("非法输入\n");
        }
    }while (n != 1);
}
//函数功能：显示游戏方格
void Show(int a[4][4])
{
    printf("      2048游戏\n");
    printf("---------------------\n");
    printf("|%4d|%4d|%4d|%4d|\n",a[0][0],a[0][1],a[0][2],a[0][3]);
    printf("|%4d|%4d|%4d|%4d|\n",a[1][0],a[1][1],a[1][2],a[1][3]);
    printf("|%4d|%4d|%4d|%4d|\n",a[2][0],a[2][1],a[2][2],a[2][3]);
    printf("|%4d|%4d|%4d|%4d|\n",a[3][0],a[3][1],a[3][2],a[3][3]);
    printf("---------------------\n");
}
//函数功能：判断胜负
void Judge(int a[4][4])
{
    int i, j, n = 0, flag = 0, max = 2;
    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            if (a[i][j] == 0)
            {
                n++;
            }
            if (a[i][j] >= N)
            {
                flag = 1;
            }
            if (a[i][j] > max)
            {
                max = a[i][j];
            }
        }
    }
    if (n <= 1)
    {
        printf("You lost!\n");
        printf("Your score is %d",max);
        exit(0);
    }
    if (flag == 1)
    {
        printf("You win!");
        exit(0);
    }
}
//函数功能：向上移动
int MoveUp(int a[4][4])
{
    int i, j, k, flag = 0;
    for (k=0; k<3; k++)
    {
        for (j=0; j<4; j++)
        {
            for (i=1; i<=3; i++)
            {
                if ((a[i][j]==a[i-1][j]||a[i-1][j]==0) && (a[i][j]!=0))
                {
                    a[i-1][j] = a[i-1][j]+a[i][j];
                    a[i][j] = 0;
                    flag = 1;
                }
            }
        }
    }
    return flag;
}
//函数功能：向下移动
int MoveDown(int a[4][4])
{
    int i, j, k, flag = 0;
    for (k=0; k<3; k++)
    {
        for (j=0; j<4; j++)
        {
            for (i=2; i>=0; i--)
            {
                if ((a[i][j]==a[i+1][j]||a[i+1][j]==0) && (a[i][j]!=0))
                {
                    a[i+1][j] = a[i+1][j]+a[i][j];
                    a[i][j] = 0;
                    flag = 1;
                }
            }
        }
    }
    return flag;
}
//函数功能：向左移动
int MoveLeft(int a[4][4])
{
    int i, j, k, flag = 0;
    for (k=0; k<3; k++)
    {
        for (i=0; i<4; i++)
        {
            for (j=1; j<=3; j++)
            {
                if ((a[i][j]==a[i][j-1]||a[i][j-1]==0) && (a[i][j]!=0))
                {
                    a[i][j-1] = a[i][j-1]+a[i][j];
                    a[i][j] = 0;
                    flag = 1;
                }
            }
        }
    }
    return flag;
}
//函数功能：向右移动
int MoveRight(int a[4][4])
{
    int i, j, k, flag = 0;
    for (k=0; k<3; k++)
    {
        for (i=0; i<4; i++)
        {
            for (j=2; j>=0; j--)
            {
                if ((a[i][j]==a[i][j+1]||a[i][j+1]==0) && (a[i][j]!=0))
                {
                    a[i][j+1] = a[i][j+1]+a[i][j];
                    a[i][j] = 0;
                    flag = 1;
                }
            }
        }
    }
    return flag;
}
