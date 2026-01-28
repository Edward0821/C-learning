#include  <stdio.h>
int main(void)
{
	float  h, w, t;
	printf("Please enter h,w:");
	scanf("%f, %f", &h, &w);
	t = w / (h * h);
	if (t < 18)
		printf("t=%f\tLower weight!\n", t);
	else  if (t < 25)
		printf("t=%f\tStandard weight!\n", t);
	else  if (t < 27)
		printf("t=%f\tHigher weight!\n", t);
	else
		printf("t=%f\tToo fat!\n", t);
    return 0;
}
