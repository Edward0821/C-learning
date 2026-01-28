#include <stdio.h>
#define N   80
int CopyFile(const char *srcName, const char *dstName);
int main(void)
{
	char srcFilename[N];					/* 源文件名 */
	char dstFilename[N];					/* 目标文件名 */
	printf("Input source filename:");
	scanf("%s", srcFilename);        		/*输入源文件名*/
	printf("Input destination filename:");
	scanf("%s", dstFilename);        		/*输入目标文件名*/
	if (CopyFile(srcFilename, dstFilename))/*文件复制*/
	{
		printf("Copy succeed!\n");
	}
	else
	{
		printf("Copy failed!\n");
	}
	return 0;
}
/* 函数功能：把srcName文件内容复制到dstName文件中，返回非0值表示复制成功 */
int CopyFile(const char *srcName, const char *dstName)
{
	FILE *fpSrc = NULL, *fpDst = NULL;
	int	  ch, rval = 1;
	if ((fpSrc = fopen(srcName,"r")) == NULL)
	{
		goto ERROR;
	}
	if ((fpDst = fopen(dstName,"w")) == NULL)
	{
		goto ERROR;
	}
	while ((ch=fgetc(fpSrc)) != EOF) /* 复制文件 */
	{
		if (fputc(ch, fpDst) == EOF)	goto ERROR;
	}
	fflush(fpDst);				/* 确保存盘 */
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
