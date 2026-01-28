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
	float aver;                   /* 4门课程的 平均分 */
}STUDENT;
void InputScore(STUDENT stu[], int n, int m);
void AverScore(STUDENT stu[], int n, int m);
void WritetoFile(STUDENT stu[], int n);
int  ReadfromFile(STUDENT stu[]);
void PrintScore(STUDENT stu[], int n, int m);
int main(void)
{
	STUDENT stu[N];
	int n, m = 4;
	printf("How many student?");
	scanf("%d", &n);
	InputScore(stu, n, m);
	AverScore(stu, n, m);
	WritetoFile(stu, n);
	n = ReadfromFile(stu);
	PrintScore(stu, n, m);
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
	int i, j, sum[N];
	for (i=0; i<n; i++)
	{
		sum[i] = 0;
		for (j=0; j<m; j++)
		{
			sum[i] = sum[i] + stu[i].score[j];
		}
		stu[i].aver = (float)sum[i]/m;
	}
}
/* 输出n个学生的学号、姓名、性别、出生日期以及m门课程的成绩到文件student.txt中 */
void WritetoFile(STUDENT stu[], int n)
{
	FILE *fp;
	if ((fp = fopen("student.txt","w")) == NULL) /* 以写方式打开文本文件 */
	{
		printf("Failure to open student.txt!\n");
		exit(0);
	}
	fwrite(stu, sizeof(STUDENT), n, fp);           /* 按数据块写文件 */
	fclose(fp);
}
/*从文件中读取学生的学号、姓名、性别、出生日期及成绩到结构体数组stu中并返回学生数*/
int ReadfromFile(STUDENT stu[])
{
	FILE *fp;
	int i;
	if ((fp = fopen("student.txt","r")) == NULL) /* 以读方式打开文本文件 */
	{
		printf("Failure to open student.txt!\n");
		exit(0);
	}
	for (i=0; !feof(fp); i++)
	{
		fread(&stu[i], sizeof(STUDENT), 1, fp); /* 按数据块读文件 */
	}
	fclose(fp);
	printf("Total students is %d.\n", i-1); /* 返回文件中的学生记录数 */
	return i-1; /* 返回文件中的学生记录数 */
}
/* 输出n个学生的学号、姓名、性别、出生日期、m门课程的成绩及平均分到屏幕上 */
void PrintScore(STUDENT stu[], int n, int m)
{
	int i, j;
	for (i=0; i<n; i++)
	{
		printf("%10ld%8s%3c%6d/%02d/%02d",
		stu[i].studentID, stu[i].studentName, stu[i].stuGender,
		stu[i].birthday.year, stu[i].birthday.month, stu[i].birthday.day);
		for (j=0; j<m; j++)
		{
			printf("%4d", stu[i].score[j]);
		}
		printf("%6.1f\n", stu[i].aver);
	}
}
