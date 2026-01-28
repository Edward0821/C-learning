#include <stdio.h>
#include <stdlib.h>
#define SIZE   51
int BigFact(int m, int data[]);
int main(void)
{
	int data[SIZE] = {0};/* 存储50位数，元素全部初始化为0，不使用data[0] */
	int index;              /* 数组元素个数，表示阶乘值的位数 */
	int n;                   /* 准备计算的阶乘中的最大数 */
	int i, j;
	printf("Input n:");
	scanf("%d", &n);
	for (i=1; i<=n; i++)    /* 计算从1到n之间所有数的阶乘值 */
	{
		index = BigFact(i, data);/* 计算阶乘i!，返回阶乘值的位数 */
		if (index != 0)     /* 检验数组是否溢出，若未溢出，则打印阶乘值 */
		{
			printf("%d! = ", i);
			for (j=index; j>0; j--) /* 从最高位开始打印每一位阶乘值 */
			{
				printf("%d", data[j]);
			}
			printf("\n");
		}
		else                     /* 若大于50，数组溢出，则提示错误信息 */
		{
			printf("Over flow!\n");
			exit(1);
		}
	}
	return 0;
}
/*函数功能：计算m!，存于数组data中，若数组未溢出，则返回阶乘值的位数，否则返回0*/
int BigFact(int m, int data[])
{
   	int i, j, k;
	int index = 1;         /* 数组元素个数，表示阶乘值的位数 */
	for (i=0; i<SIZE; i++)
	{
		data[i] = 0;        /* 每个数组元素存储阶乘值的每一位数字，全部初始化为0 */
	}
	data[1] = 1;           /* 初始化，令1!=1 */
	for (i=1; i<=m; i++)  /* 计算阶乘m! */
	{
		for (j=1; j<=index; j++)
		{
			data[j] = data[j] * i;/* 每一位数字都乘以i */
		}
		for (k=1; k<index; k++)
		{
			if (data[k] >= 10)/* 阶乘值的每位数字应在0~9之内，若>=10，则进位 */
			{
				data[k+1] = data[k+1] + data[k]/10; /* 当前位向前进位 */
				data[k] = data[k] % 10;               /* 进位之后的值 */
			}
		}
		/* 单独处理最高位，若计算之后的最高位>=10，则位数index加1 */
		while (data[index] >= 10 && index <= SIZE-1)
		{
			data[index+1] = data[index] / 10;  /* 向最高位进位 */
			data[index] = data[index] % 10;    /* 进位之后的值 */
			index++;                                /* 位数index加1 */
		}
	}
	if (index <= SIZE-1)/* 检验数组是否溢出，若未溢出，则返回阶乘值的位数 */
		return index;
	else                  /* 若大于50，数组溢出，则返回0值 */
		return 0;
}
