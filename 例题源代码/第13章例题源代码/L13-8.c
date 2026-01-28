#include  <stdio.h>
#include  <stdlib.h>
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
	float aver;                   /* 平均分 */
}STUDENT;
void SearchinFile(char fileName[], long k);
int main(void)
{
	long k;
	printf("Input the searching record number:");
	scanf("%ld", &k);
	SearchinFile("student.txt", k);
	return 0;
}
/* 从文件fileName中查找并显示第k条记录的数据 */
void SearchinFile(char fileName[], long k)
{
	FILE *fp;
	int j;
	STUDENT stu;
	if ((fp = fopen(fileName,"r")) == NULL) /* 以读方式打开文本文件 */
	{
		printf("Failure to open %s!\n", fileName);
		exit(0);
	}
	fseek(fp, (k-1)*sizeof(STUDENT), SEEK_SET);
	fread(&stu, sizeof(STUDENT), 1, fp); /* 按数据块读文件 */
	printf("%10ld%8s%3c%6d/%02d/%02d",
		stu.studentID, stu.studentName, stu.stuGender,
		stu.birthday.year, stu.birthday.month, stu.birthday.day);
	for (j=0; j<4; j++)
	{
		printf("%4d", stu.score[j]);
	}
	printf("%6.1f\n", stu.aver);
	fclose(fp);
}
