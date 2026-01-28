#include  <stdio.h>
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
	int	score[4];		         /* 4门课程的成绩 */
}STUDENT;
void InputScore(STUDENT stu[], int n, int m);
void AverScore(STUDENT stu[], float aver[], int n, int m);
void PrintScore(STUDENT stu[], float aver[], int n, int m);
int main(void)
{
	float aver[N];
	STUDENT stu[N];
	int n;
	printf("How many student?");
	scanf("%d", &n);
	InputScore(stu, n, 4);
	AverScore(stu, aver, n, 4);
	PrintScore(stu, aver, n, 4);
	return 0;
}
/* 输入n个学生的学号、姓名、性别、出生日期以及m门课程的成绩到结构体数组stu中 */
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
void AverScore(STUDENT stu[], float aver[], int n, int m)
{
	int i, j, sum[N];
	for (i=0; i<n; i++)
	{
		sum[i] = 0;
		for (j=0; j<m; j++)
		{
			sum[i] = sum[i] + stu[i].score[j];
		}
		aver[i] = (float)sum[i]/m;
	}
}
/* 输出n个学生的学号、姓名、性别、出生日期以及m门课程的成绩 */
void PrintScore(STUDENT stu[], float aver[], int n, int m)
{
	int i, j;
	printf("Results:\n");
	for (i=0; i<n; i++)
	{
		printf("%10ld%8s%3c%6d/%02d/%02d", stu[i].studentID,
			stu[i].studentName,
			stu[i].stuGender,
			stu[i].birthday.year,
			stu[i].birthday.month,
			stu[i].birthday.day);
		for (j=0; j<m; j++)
		{
			printf("%4d", stu[i].score[j]);
		}
		printf("%6.1f\n", aver[i]);
	}
}
