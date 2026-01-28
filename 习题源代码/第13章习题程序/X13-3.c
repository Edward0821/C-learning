#include  <stdio.h>
#include  <stdlib.h>
#define N 30
typedef struct date
{
	int   year;
	int   month;
	int   day;
}DATE;
typedef struct student
{
	long  studentID;			/* 学号 */
	char  studentName[10];	     /* 姓名 */
	char  stuGender;			/* 性别 */
	DATE  birthday;			     /* 出生日期 */
	int	  score[4];		         /* 4门课程的成绩 */
	float aver;                   /* 4门课程的平均分 */
}STUDENT;
int SearchNuminFile(char fileName[], long key);
int main(void)
{
	int n;
	long key;
	printf("Input the searching ID:");
	scanf("%d", &key);
	n = SearchNuminFile("student.txt", key);
	if (n != -1)
	{
	    printf("It is the %dth record.\n", n);
	}
	else
	{
	    printf("Not found.\n");
    }
    return 0;
}

/*从文件fileName中查找并输出学号为key的记录信息，若找到，返回记录号，否则返回-1*/
int SearchNuminFile(char fileName[], long key)
{
	FILE *fp;
	STUDENT stu[N];
	int i, j;
	if ((fp = fopen(fileName, "r")) == NULL) /* 以读方式打开文本文件 */
	{
		printf("Failure to open %s!\n", fileName);
		exit(0);
	}
	for (i=0; !feof(fp); i++)
	{
		fread(&stu[i], sizeof(STUDENT), 1, fp); /* 按数据块读文件 */
		if (key == stu[i].studentID)
		{
			printf("%10ld%8s%3c%6d/%02d/%02d", stu[i].studentID,
				stu[i].studentName,
				stu[i].stuGender,
				stu[i].birthday.year,
				stu[i].birthday.month,
				stu[i].birthday.day);
			for (j=0; j<4; j++)
			{
				printf("%4d", stu[i].score[j]);
			}
			printf("%6.1f\n", stu[i].aver);
			fclose(fp);
			return i+1;         /* 若找到，则返回记录号 */
		}
	}
	fclose(fp);
	return -1;                   /* 若未找到，则返回-1 */
}
