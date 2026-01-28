#include <stdio.h>
#include <stdlib.h>
#define N 50      //数组的最大长度，需要足够大以保存用户的键盘输入数据
int main(void)
{
    char msg[N];
	FILE *fp;
	if ((fp = fopen("demo.txt","w")) == NULL) //以写方式打开文件
    {
        printf("Failure to open demo.txt!\n");
        exit(0);
    }
    fgets(msg, sizeof(msg), stdin); 
    fputs(msg, fp);  
    fclose(fp);      //关闭文件    

    if ((fp = fopen("demo.txt","r")) == NULL) //以读方式打开文件
    {
		printf("Failure to open demo.txt!\n");
		exit(0);
    }
    fgets(msg, sizeof(msg), fp); 
    printf("读出的内容为：%s\n", msg);
    fclose(fp);                   // 关闭文件
    return 0;
}