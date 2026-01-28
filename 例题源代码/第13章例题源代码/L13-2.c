#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	FILE *fp;
	char ch;
	int i;
	if ((fp = fopen("demo.bin","wb")) == NULL) /* 以二进制写方式打开文件 */
	{
		printf("Failure to open demo.bin!\n");
		exit(0);
	}
	for (i=0; i<128; i++)
	{
		fputc(i, fp);     /* 将ASCII码值在0-127之间的所有字符写入文件 */
	}
	fclose(fp);
	if ((fp = fopen("demo.bin","rb")) == NULL) /* 以二进制读方式打开文件 */
	{
		printf("Failure to open demo.bin!\n");
		exit(0);
	}
	while ((ch = fgetc(fp)) != EOF)     /* 从文件中读取字符直到文件末尾 */
	{
		putchar(ch);         /* 在显示器上显示从文件读出的所有字符 */
	}
	fclose(fp);
	return 0;
}
