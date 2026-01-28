//参考程序1
#include <stdio.h>
#include <string.h>
#define N 32   // 关键字数量
#define M 20   // 输入的单词数
#define LEN 10 // 每个单词的最大长度
int IsKeyword(char s[]);
int main(void)
{
    char word[M];
    printf("Input a keyword:");
    gets(word);
    if (IsKeyword(word) != -1)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}
// 函数功能：判断s是否是C语言关键字，若是，则返回其下标，否则返回-1
int IsKeyword(char s[])
{
    char keywords[N][LEN] = {"auto", "break", "case", "char", "const",
                               "continue", "default", "do", "double","else",
                               "enum", "extern", "float", "for", "goto",
                               "if", "int", "long", "register", "return",
                               "short", "singed", "sizeof", "static", 
                               "struct", "switch", "typedef", "union",
                               "unsigned", "void", "volatile", "while"
                            };//二维字符数组构造关键字词典
    for (int i=0; i<N; i++)//线性查找字符串s是否在关键字字典中
    {
        if (strcmp(s, keywords[i]) == 0)  return i;
    }
    return -1;   
}

//参考程序2
#include <stdio.h>
#include <string.h>
#define N 32   // 关键字数量
#define M 20   // 输入的单词数
#define LEN 10 // 每个单词的最大长度
int IsKeyword(char s[]);
int BinSearch(char keywords[][LEN], char s[], int n);
int main(void)
{
    char word[M];
    printf("Input a keyword:");
    gets(word);
    if (IsKeyword(word) != -1)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}
// 函数功能：判断s是否是C语言关键字，若是，则返回其下标，否则返回-1
int IsKeyword(char s[])
{
    char keywords[N][LEN] = {"auto", "break", "case", "char", "const",
                               "continue", "default", "do", "double","else",
                               "enum", "extern", "float", "for", "goto",
                               "if", "int", "long", "register", "return",
                               "short", "singed", "sizeof", "static", 
                               "struct", "switch", "typedef", "union",
                               "unsigned", "void", "volatile", "while"
                              };//二维字符数组构造关键字词典
    return BinSearch(keywords, s, N);      //在关键字字典中二分查找字符串s   
}
//函数功能：用二分法查找字符串s是否在n个关键字字典中
int BinSearch(char keywords[][LEN], char s[], int n)
{
    int  low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (strcmp(s, keywords[mid]) > 0)
        {
            low = mid + 1; //在后一子表查找
        }
        else  if (strcmp(s, keywords[mid]) < 0)
        {
            high = mid - 1; //在前一子表查找
        }
        else
        {
            return mid; //返回找到的位置下标
        }
    }
    return -1; //没找到
}
