#include <stdio.h>
int main(void)
{
	int year, month;

	printf("Input year,month: ");
	scanf("%d, %d", &year, &month);			/*输入相应的年和月*/
	switch (month)
	{
	    case 1:
	    case 3:
	    case 5:
	    case 7:
	    case 8:
	    case 10:
	    case 12:
		    printf("31 days\n");
		    break;
	    case 2:
			if (year % 4== 0 && year % 100 != 0 || year % 400 == 0)
			{
				printf("29 days\n");    	/*闰年的2月有29天 */
			}
			else
			{
				printf("28 days\n");		/*平年的2月有28天 */
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			printf("30 days\n");
			break;
		default:
			printf("Input error!\n");
	}
	return 0;
}
