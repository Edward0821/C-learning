#include  <stdio.h>
#include  <string.h>
#define   MAX_LEN  10             /* 字符串最大长度 */
#define   N         150            /* 字符串个数 */
void SortString(char *ptr[], int n);
int main(void)
{
	int    i, n;
	char   name[N][MAX_LEN];    /* 定义二维字符数组 */
	char   *pStr[N];	         /* 定义字符指针数组 */
	printf("How many countries?");
	scanf("%d",&n);
	getchar();                    /* 读走输入缓冲区中的回车符 */
	printf("Input their names:\n");
	for (i=0; i<n; i++)
	{
		pStr[i] = name[i];    /* 让pStr[i]指向二维字符数组name的第i行 */
		gets(pStr[i]);         /* 输入第i个字符串到pStr[i]指向的内存 */
	}
	printf("Before sorted:\n");
	printf("pStr[i]   pStr[i] point to   name[i]\n");
	for (i=0; i<n; i++)
	{
		printf("%-10p",pStr[i]); /* 输出排序前的n个字符串的首地址 */
		printf("%13s%13s\n", pStr[i], name[i]); /* 输出排序前的n个字符串 */
	}
	SortString(pStr, n);           /* 字符串按字典顺序排序 */
	printf("After sorted:\n");
	printf("pStr[i]   pStr[i] point to   name[i]\n");
	for (i=0; i<n; i++)
	{
		printf("%-10p",pStr[i]); /* 输出排序后的n个字符串的首地址 */
		printf("%13s%13s\n", pStr[i], name[i]); /* 输出排序后的n个字符串 */
	}
	return 0;
}

/*函数功能：用指针数组作函数参数，采用交换法实现字符串按字典顺序排序 */
void SortString(char *ptr[], int n)
{
	int    i, j;
	char  *temp = NULL;  /* 因交换的是字符串的地址值，故temp定义为指针变量 */
	for (i=0; i<n-1; i++)
	{
		for (j = i+1; j<n; j++)
		{
			if (strcmp(ptr[j], ptr[i]) < 0)  /* 交换指向字符串的指针 */
			{
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
}
