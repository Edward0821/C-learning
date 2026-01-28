#include <stdio.h>
#include <string.h>
#define N 80
int main(void)
{
	char  dest[N] = "习近平总书记";
	char  *src = "在党的二十大报告中指出：\"青年强，则国家强。\" ";
	strcat(dest, src);
        printf("%s\n", dest);
	return 0;
}
