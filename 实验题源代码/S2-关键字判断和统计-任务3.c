//参考程序1
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 32   //关键字数量
#define M 50   //输入的句子中的字符数
#define LEN 10 //每个单词的最大长度
int InputWord(char s[][LEN]);
void OutputCountResults(char *keywords[] , int count[], int n);
int IsKeyword(char s[]);
void CountKeywords(char s[][LEN], int n);
int main(void)
{
    char s[M][LEN];      
    int n = InputWord(s);    
    CountKeywords(s, n);    
    return 0;
}
//函数功能：以空格符作为分隔符输入包含多个单词的字符序列，切分单词并保存到二维字符数组
int InputWord(char word[][LEN])
{
    char s[M];
    gets(s);
    int i = 0, j = 0, k = 0, flag = 0;    
    //去掉字符串前面多余的空格
    while (isspace(s[i]))
    {
        i++;
    }
    for (; s[i]!='\0'; i++)
    {
        if (isalpha(s[i]))
        {
            word[j][k] = s[i];
            k++;
            flag = 0; //必须有，否则第3个单词无法分离
        }
        else if (!flag)//必须有，否则单词之间的多余空格无法处理
        {
            word[j][k] = '\0';//必须有，否则第一个单词统计结果显示不出来
            j++;
            k = 0;
            flag = 1;
        }
    }
    word[j][k] = '\0';//必须有，否则最后一个单词统计结果少1
    return j+1;
}
//函数功能：输出关键字统计结果
void OutputCountResults(char *keywords[], int count[], int n)
{
    printf("Results:\n");
    for (int i=0; i<n; i++)
    {
        if (count[i] != 0)
        {
            printf("%s:%d\n", keywords[i], count[i]);
        }
    }
}
//函数功能：判断s是否是C语言关键字，若是，则返回其下标，否则返回-1
int IsKeyword(char s[])
{
    char *keywords[N] = {"auto", "break", "case", "char", "const",
                           "continue", "default", "do", "double","else",
                           "enum", "extern", "float", "for", "goto",
                           "if", "int", "long", "register", "return",
                           "short", "singed", "sizeof", "static", 
                           "struct", "switch", "typedef", "union",
                           "unsigned", "void", "volatile", "while"
}; //字符指针数组构造关键字词典
    for (int i=0; i<N; i++)//线性查找字符串s是否在关键字字典中
    {
        if (strcmp(s, keywords[i]) == 0)  return i;
    }
    return -1;
}
//函数功能：统计二维字符数组s中关键字的数量存于结构体数组keywords的count成员中
void CountKeywords(char s[][LEN], int n)
{     
    char *keywords[N] = {"auto", "break", "case", "char", "const",
                           "continue", "default", "do", "double","else",
                           "enum", "extern", "float", "for", "goto",
                           "if", "int", "long", "register", "return",
                           "short", "singed", "sizeof", "static", 
                           "struct", "switch", "typedef", "union",
                           "unsigned", "void", "volatile", "while"
}; //字符指针数组构造关键字词典
    int count[N] = {0};
    for (int i=0; i<n; i++)
    {
        int k = IsKeyword(s[i]);
        if (k != -1)
        {
            count[k]++;
        }
    }
    OutputCountResults(keywords, count, N);
}
//参考程序2
#include <stdio.h>
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
int InputWord(char s[][LEN]);
void OutputCountResults(KEY keywords[], int n);
int IsKeyword(char s[]);
int BinSearch(KEY keywords[], char s[], int n);
void CountKeywords(char s[][LEN], int n);
int main(void)
{
    char s[M][LEN];      
    int n = InputWord(s);    
    CountKeywords(s, n);    
    return 0;
}
//函数功能：以空格符作为分隔符输入包含多个单词的字符序列，切分单词并保存到二维字符数组
int InputWord(char word[][LEN])
{
    char s[M];
    gets(s);
    int i = 0, j = 0, k = 0, flag = 0;    
    //去掉字符串前面多余的空格
    while (isspace(s[i]))
    {
        i++;
    }
    for (; s[i]!='\0'; i++)
    {
        if (isalpha(s[i]))
        {
            word[j][k] = s[i];
            k++;
            flag = 0; //必须有，否则第3个单词无法分离
        }
        else if (!flag)//必须有，否则单词之间的多余空格无法处理
        {
            word[j][k] = '\0';//必须有，否则第一个单词统计结果显示不出来
            j++;
            k = 0;
            flag = 1;
        }
    }
    word[j][k] = '\0';//必须有，否则最后一个单词统计结果少1
    return j+1;
}
// 函数功能：输出关键字统计结果
void OutputCountResults(KEY keywords[], int n)
{
    printf("Results:\n");
    for (int i = 0; i < n; i++)
    {
        if (keywords[i].count != 0)
        {
            printf("%s:%d\n", keywords[i].word, keywords[i].count);
        }
    }
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
    OutputCountResults(keywords, N);
}

