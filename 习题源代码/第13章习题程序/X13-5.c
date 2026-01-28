#include <stdio.h>
#define N   80
int AppendFile(const char *srcName, const char *dstName);
int main(void)
{
	char srcFilename[N];					/* 源文件名 */
	char dstFilename[N];					/* 目标文件名 */
	printf("Input source filename:");
	scanf("%s", srcFilename);        		/* 输入源文件名 */
	printf("Input destination filename:");
	scanf("%s", dstFilename);        		/* 输入目标文件名 */
	if (AppendFile(srcFilename, dstFilename))/* 文件追加 */
	{
		printf("Append succeed!\n");
	}
	else
	{
		printf("Append failed!\n");
	}
	return 0;
}
/* 函数功能：把srcName文件内容复制到dstName，返回非0值表示复制成功 */
int AppendFile(const char *srcName, const char *dstName)
{
	FILE *fpSrc = NULL, *fpDst = NULL;
	int	ch, rval = 1;
	if ((fpSrc = fopen(srcName,"r")) == NULL) 	/* 只读方式打开源文件 */
	{
		goto ERROR;
	}
	if ((fpDst = fopen(dstName,"a")) == NULL) 	/* 追加方式打开目标文件 */
	{
		goto ERROR;
	}
	while ((ch=fgetc(fpSrc)) != EOF) /* 文件追加 */
	{
		if (fputc(ch, fpDst) == EOF)
		{
			goto ERROR;
		}
	}
	fflush(fpDst);	/* 确保存盘 */
	goto EXIT;
ERROR:
	rval = 0;
EXIT:
	if (fpSrc != NULL)
	{
		fclose(fpSrc);
	}
	if (fpDst != NULL)
	{
		fclose(fpDst);
	}
	return rval;
}
