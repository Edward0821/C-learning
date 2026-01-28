#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define N 100
#define M 100
int score;
FILE *fp;
char UserInput(char str[][M], int exitx, int exity, int n, char c);
void Show (char str[][M], int n);//显示画面
int main(void)
{
    int i = 0;
    char ch[N][M], c;
    do{
        system("cls");
        printf("******************************************\n"
           "*                迷宫游戏                *\n"
           "*                                        *\n"
           "*    选择难度：简单-输入 1               *\n"
           "*              中等-输入 2               *\n"
           "*              困难-输入 3               *\n"
           "*                                        *\n"
           "*    退出游戏：输入 0                    *\n"
           "*                                        *\n"
           "******************************************\n");
        i = 0;
        c = getchar();
        while (getchar() != '\n');
        switch (c)
        {
            case '1':
                if ((fp = fopen("dome1.txt","r")) == NULL)
                {
                    printf("Failure to open dome.txt!\n");
                    exit(0);
                }
                else
                {
                    while (fgets(ch[i], 25, fp))
                    {
                        i++;
                    }
                }
                Show(ch, i);
                c = UserInput(ch, 12, 22, i, c);
                fclose(fp);
                break;
            case '2':
                if ((fp = fopen("dome2.txt","r")) == NULL)
                {
                    printf("Failure to open dome.txt!\n");
                    exit(0);
                }
                else
                {
                    while (fgets(ch[i], 41, fp))
                   {
                        i++;
                   }
                }
                Show(ch, i);
                c = UserInput(ch, 18, 38, i, c);
                fclose(fp);
                break;
            case '3':
                if ((fp = fopen("dome3.txt","r")) == NULL)
                {
                    printf("Failure to open dome.txt!\n");
                    exit(0);
                }
                else
                {
                    while (fgets(ch[i], 61, fp))
                    {
                        i++;
                    }
                }
                Show(ch, i);
                c = UserInput(ch, 23, 58, i, c);
                fclose(fp);
                break;
            case '0':
                printf("good bye");
                break;
        }
    }while (c != '0');
    return 0;
}
//函数功能：提取玩家的操作，做相应的数据和位置更新，判断游戏是否结束
char UserInput(char str[][M], int exitx, int exity, int n, char c)
{
    int x = 1, y = 1;
    char input;
    while (x != exitx || y != exity)
    {
        if (kbhit())//判断用户是否输入
        {
            input = getch();
            if (input == 'a' && str[x][y-1] != '*')//向左移动
            {
                if (str[x][y-1] == 'o')
                {
                    score = score + 10;
                }
                str[x][y] = ' ';
                y--;               //向左移动
                str[x][y] = '@';
            }
            if (input == 'd' && str[x][y+1] != '*')//向右移动
            {
                if (str[x][y+1] == 'o')
                {
                    score = score + 10;
                }
                str[x][y] = ' ';
                y++;                //向右移动
                str[x][y] = '@';
            }
            if (input=='s' && str[x+1][y] != '*')//向下移动
            {
                if (str[x+1][y] == 'o')
                {
                    score = score + 10;
                }
                str[x][y] = ' ';
                x++;               //向下移动
                str[x][y] = '@';
            }
            if (input == 'w' && str[x-1][y] != '*')//向上移动
            {
                if (str[x-1][y] == 'o')
                {
                    score = score + 10;
                }
                str[x][y] = ' ';
                x--;               //向上移动
                str[x][y] = '@';
            }
            if (input == '0')//退出程序
            {
                system("cls");
                return c;
            }
        }
        system("cls");
        Show(str, n);
        printf("score=%d\n", score);
        printf("输入 0 退出游戏\n");
        Sleep(300);
    }
    system("cls");
    printf("final score=%d\n",score);
    printf("you win!\n");//完成游戏，显示胜利
    printf("是否继续游戏，是-Y，否-N\n");
    scanf(" %c", &input);//%c前面有一个空格
    if (input == 'Y' || input == 'y')
    {
        return c;
    }
    else
    {
        return '0';
    }
}
//函数功能：显示迷宫地图
void Show(char str[][M], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("%s", str[i]);
    }
}
