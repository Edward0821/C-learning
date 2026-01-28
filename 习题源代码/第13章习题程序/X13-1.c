#include <stdio.h>
#include  <stdlib.h>
int type(const char* fileName);
int main(int argc, char *argv[])
{
	int i;
	if (argc < 2)
	{
		printf("The syntax of the command is incorrect.\n");
		exit(0);
	}
	for (i=1; i<argc; i++)/* 把除argv[0]外的所有参数代表的文件内容逐一输出 */
	{
		if (type(argv[i]) == 0)
		{
		    printf("No such a file: %s\n", argv[i]);
		}
	}
	return 0;
}
/*  函数功能：把文件fileName内容输出到屏幕，函数返回非0值时表示成功，否则出错 */
int type(const char* fileName)
{
	int val = 1;                                /* 成功操作时的返回值为1 */
	FILE *fp;
	char ch;
	if ((fp = fopen(fileName,"r")) == NULL)/* 判断文件是否成功打开 */
	{
	    val = 0;                                 /* 打开文件失败时的返回值为0 */
	}
	else
	{
        printf("The contents of file %s:\n", fileName);
	    while ((ch = fgetc(fp)) != EOF)     /* 从文件读取字符直到文件尾 */
	    {
	        fputc(ch, stdout);                 /* 在显示器上显示字符 */
	    }
	    fclose(fp);
	}
	return val;                                  /* 返回val的值 */
}
