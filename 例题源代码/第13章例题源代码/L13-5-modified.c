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
	float aver;                   /* 平均分 */
}STUDENT;
void InputScore(STUDENT stu[], int n, int m);
void AverScore(STUDENT stu[], int n, int m);
void WritetoFile(STUDENT stu[], int n, int m);
int main(void)
{
	STUDENT stu[N];
	int n;
	printf("How many student?");
	scanf("%d", &n);
	InputScore(stu, n, 4);
	AverScore(stu, n, 4);
	WritetoFile(stu, n, 4);
    return 0;
}
/*从键盘输入n个学生的学号、姓名、性别、出生日期以及m门课程的成绩到结构体数组stu中*/
void InputScore(STUDENT stu[], int n, int m)
{
	int i, j;
	for (i=0; i<n; i++)
	{
		printf("Input record %d:\n", i+1);
		scanf("%ld", &stu[i].studentID);
		scanf("%s", stu[i].studentName);
		scanf(" %c", &stu[i].stuGender); /* %c前有一个空格 */
		scanf("%d", &stu[i].birthday.year);
		scanf("%d", &stu[i].birthday.month);
		scanf("%d", &stu[i].birthday.day);
		for (j=0; j<m; j++)
		{
			scanf("%d", &stu[i].score[j]);
		}
	}
}
/* 计算n个学生的m门课程的平均分，存入数组aver中 */
void AverScore(STUDENT stu[], int n, int m)
{
	int i, j, sum;
	for (i=0; i<n; i++)
	{
		sum = 0;
		for (j=0; j<m; j++)
		{
			sum = sum + stu[i].score[j];
		}
		stu[i].aver = (float)sum/m;
	}
}
/* 输出n个学生的学号、姓名、性别、出生日期以及m门课程的成绩到文件score.txt中 */
void WritetoFile(STUDENT stu[], int n, int m)
{
	FILE *fp;
	int i, j;
	if ((fp = fopen("score.txt","w")) == NULL) /* 以写方式打开文本文件 */
	{
		printf("Failure to open score.txt!\n");
		exit(0);
	}
     fprintf(fp, "%d\t%d\n", n, m);    /*将学生人数和课程门数写入文件*/
	for (i=0; i<n; i++)
	{
		fprintf(fp, "%10ld%8s%3c%6d/%02d/%02d",  stu[i].studentID,
stu[i].studentName,
stu[i].stuGender,
stu[i].birthday.year,
stu[i].birthday.month,
stu[i].birthday.day);
		for (j=0; j<m; j++)
		{
			fprintf(fp, "%4d", stu[i].score[j]);
		}
		fprintf(fp, "%6.1f\n", stu[i].aver);
	}
	fclose(fp);
}
