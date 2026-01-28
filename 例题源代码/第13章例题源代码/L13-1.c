#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	FILE *fp;
	char ch;
	if ((fp = fopen("demo.txt","w")) == NULL) /* 判断文件是否成功打开 */
	{
		printf("Failure to open demo.txt!\n");
		exit(0);
	}
	ch = getchar();
	while (ch != '\n')   /* 若键入回车换行符则结束键盘输入和文件写入 */
	{
		fputc(ch, fp);
        ch = getchar();
	}
	fclose(fp);           /* 关闭由函数fopen()打开的文件demo.txt */
	return 0;
}
