#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 32   //关键字数量
#define M 50   //输入的句子中的字符数
#define LEN 10 //每个单词的最大长度
typedef struct key
{
    char word[LEN];
    int  count;
}KEY;
int InputFromFile(char fileName[], char token[][LEN]);
void OutputToFile(char fileName[], KEY keywords[], int n);
int IsKeyword(char s[]);
int BinSearch(KEY keywords[], char s[], int n);
void CountKeywords(char s[][LEN], int n);
int main(void)
{
    char s[M][LEN];      
    int n = InputFromFile("code.txt", s);    
    CountKeywords(s, n);    
    return 0;
}
//函数功能：从文件中读取字符串并
int InputFromFile(char fileName[], char token[][LEN])
{
    printf("Read from file %s:\n", fileName);
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("Cannot open file %s!\n", fileName);
        exit(0);
    }
    int i = 0;
    do{
        fscanf(fp, "%s", token[i]);
        i++;
    }while (strcmp(token[i-1], "end") != 0);
    fclose(fp);
    printf("Read finished!\n");
    return i - 1;
}
// 函数功能：输出关键字统计结果
void OutputToFile(char fileName[], KEY keywords[], int n)
{
    printf("Write to file %s:\n", fileName);
    FILE *fp = fopen(fileName, "w");
    if (fp == NULL)
    {
        printf("Cannot open file %s!\n", fileName);
        exit(0);
    }
    for (int i = 0; i < n; i++)
    {
        if (keywords[i].count != 0)
        {
            fprintf(fp, "%s:%d\n", keywords[i].word, keywords[i].count);
        }
    }
    fclose(fp);
    printf("Write finished!\n");
}
// 函数功能：判断s是否是C语言关键字，若是，则返回其下标，否则返回-1
int IsKeyword(char s[])
{
    KEY keywords[N] = { {"auto", 0}, {"break", 0}, {"case", 0},
                        {"char", 0}, {"const", 0}, {"continue", 0},
                        {"default", 0}, {"do", 0}, {"double", 0},
                        {"else", 0}, {"enum", 0}, {"extern", 0},
                        {"float", 0}, {"for", 0}, {"goto", 0},
                        {"if", 0}, {"int", 0}, {"long", 0},
                        {"register", 0}, {"return", 0}, {"short", 0},
                        {"singed", 0}, {"sizeof", 0}, {"static", 0},
                        {"struct", 0}, {"switch", 0}, {"typedef", 0},
                        {"union", 0}, {"unsigned", 0}, {"void", 0},
                        {"volatile", 0}, {"while", 0}
                     };//字符指针数组构造关键字词典以及关键字计数初始化
     return BinSearch(keywords, s, N);      //在关键字字典中二分查找字符串s   
}
//函数功能：用二分法查找字符串s是否在n个关键字字典中
int BinSearch(KEY keywords[], char s[], int n)
{
    int  low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (strcmp(s, keywords[mid].word) > 0)
        {
            low = mid + 1; //在后一子表查找
        }
        else  if (strcmp(s, keywords[mid].word) < 0)
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
// 函数功能：统计二维字符数组s中关键字的数量存于结构体数组keywords的count成员中
void CountKeywords(char s[][LEN], int n)
{
    KEY keywords[N] = { {"auto", 0}, {"break", 0}, {"case", 0},
                        {"char", 0}, {"const", 0}, {"continue", 0},
                        {"default", 0}, {"do", 0}, {"double", 0},
                        {"else", 0}, {"enum", 0}, {"extern", 0},
                        {"float", 0}, {"for", 0}, {"goto", 0},
                        {"if", 0}, {"int", 0}, {"long", 0},
                        {"register", 0}, {"return", 0}, {"short", 0},
                        {"singed", 0}, {"sizeof", 0}, {"static", 0},
                        {"struct", 0}, {"switch", 0}, {"typedef", 0},
                        {"union", 0}, {"unsigned", 0}, {"void", 0},
                        {"volatile", 0}, {"while", 0}
                     };//字符指针数组构造关键字词典以及关键字计数初始化    
    for (int i = 0; i < n; i++)
    {
        int k = IsKeyword(s[i]);
        if (k != -1)
        {
            keywords[k].count++;
        }
    }
    OutputToFile("result.txt", keywords, N);
}
