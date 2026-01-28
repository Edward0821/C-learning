#include  <stdio.h>
int main(void)
{
	char sex;				     /* 孩子的性别 */
	char sports;			/* 是否喜欢体育运动 */
	char diet;			/* 是否有良好的饮食习惯 */
	float myHeight;		/* 孩子身高 */
	float faHeight;		/* 父亲身高 */
	float moHeight;		/* 母亲身高 */
	printf("Are you a boy(M) or a girl(F)?");
	scanf(" %c", &sex);   /* 在%c前加一个空格，将存于缓冲区中的回车符读走 */
	printf("Please input your father's height(cm):");
	scanf("%f", &faHeight);
	printf("Please input your mother's height(cm):");
	scanf("%f", &moHeight);
	printf("Do you like sports(Y/N)?");
	scanf(" %c", &sports);/* 在%c前加一个空格，将存于缓冲区中的回车符读走 */
	printf("Do you have a good habit of diet(Y/N)?");
	scanf(" %c", &diet); /* 在%c前加一个空格，将存于缓冲区中的回车符读走 */
	if (sex == 'M' || sex == 'm')
		myHeight = (faHeight + moHeight) * 0.54;
	else
		myHeight = (faHeight * 0.923 + moHeight) / 2.0;
	if (sports == 'Y' || sports == 'y')
		myHeight = myHeight * (1 + 0.02);
	if (diet == 'Y' || diet == 'y')
		myHeight = myHeight * (1 + 0.015);
	printf("Your future height will be %.0f(cm)\n", myHeight);
	return 0;
}
