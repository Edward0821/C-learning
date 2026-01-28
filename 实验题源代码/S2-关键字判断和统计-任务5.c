#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 80
void ReadFromFile(char fileName[], char text[], int n);
int CountSubString(char target[], char pattern[]);
void WriteToFile(char fileName[], char text[], int n);
int main(void)
{
    char  text[N*10+1];
    char  pattern[N+1];
    printf("Input a paragraph:");
    gets(text);
    int len = strlen(text);
    if (len <= sizeof(text))
    {
        WriteToFile("file.txt", text, len);
        printf("Input a phrase:");
        gets(pattern);
        ReadFromFile("file.txt", text, len);
        printf("%d次\n", (CountSubString(text, pattern)));
    }
    return 0;
}
//函数功能：判断pattern在target中出现的次数
//函数参数：字符型数组target，存放目标字符串
//          实型数组pattern，存放模式子串
//函数返回值：pattern在target中出现的次数
int CountSubString(char target[], char pattern[])
{
    int i = 0, j = 0, k, n = 0; //计数器初始化
    for (i=0; target[i]!='\0'; i++) //暴力搜索
    {
        j = i;
        k = 0;  //重新回到模式串起始位置
        while (pattern[k] == target[j] && pattern[k] != '\0')
        {
            j++;
            k++;
        }

        if (pattern[k] == '\0') //if (k == strlen(pattern))
        {
            n++; //记录出现的次数
        }
    }
    return n;  //返回出现的次数
}
//函数功能：将text中的字符串写入文件
//函数参数：字符型数组filename，存放文件名
//          实型数组text，存放文件内容
//          整型变量n，存放字符数组的大小
//函数返回值：无
void ReadFromFile(char fileName[], char text[], int n)
{
    printf("Read from file: %s\n", fileName);
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("Cannot open file %s!\n", fileName);
        exit(0);
    }
    fgets(text, n, fp);
    //fscanf(fp, "%s", text);
    printf("Read finished!\n");
    fclose(fp);
}
//函数功能：从文件中读取一个以换行为结束的字符串，保存到text中
//函数参数：字符型数组filename，存放文件名
//          实型数组text，存放文件内容
//          整型变量n，存放字符数组的大小
//函数返回值：无
void WriteToFile(char fileName[], char text[], int n)
{
    printf("Write to file: %s\n", fileName);
    FILE *fp = fopen(fileName, "w");
    if (fp == NULL)
    {
        printf("Cannot open file %s!\n", fileName);
        exit(0);
    }
    fputs(text, fp);
    //fprintf(fp, "%s\n", text);
    fclose(fp);
    printf("Write finished!\n");
}
