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
	long  studentID;			// 学号
	char  studentName[10];	    // 姓名
	char  stuGender;			// 性别
	DATE  birthday;			    // 出生日期
	int	  score[4];		        // 4门课程的成绩
	float aver;                 // 平均分
}STUDENT;
void InputScore(STUDENT stu[], int n, int m);
void AverScore(STUDENT stu[], int n, int m);
void WritetoFile(STUDENT stu[], int n);
int  ReadfromFile(STUDENT stu[]);
void PrintScore(STUDENT stu[], int n, int m);
void SortScore(STUDENT stu[], int n);
void SwapStruct(STUDENT *x, STUDENT *y);
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
	SortScore(stu, n);
	PrintScore(stu, n, m);
    return 0;
}
//函数功能：输入n个学生的学号、姓名、性别、出生日期及m门课程成绩到结构体数组stu中
void InputScore(STUDENT stu[], int n, int m)
{
	for (int i=0; i<n; i++)
	{
		printf("Input record %d:\n", i+1);
		scanf("%ld", &stu[i].studentID);
		scanf("%s", stu[i].studentName);
		scanf(" %c", &stu[i].stuGender); //%c前有一个空格
		scanf("%d", &stu[i].birthday.year);
		scanf("%d", &stu[i].birthday.month);
		scanf("%d", &stu[i].birthday.day);
		for (int j=0; j<m; j++)
		{
			scanf("%d", &stu[i].score[j]);
		}
	}
}
//函数功能：计算n个学生的m门课程的平均分
void AverScore(STUDENT stu[], int n, int m)
{
	for (int i=0; i<n; i++)
	{
		int sum = 0;
		for (int j=0; j<m; j++)
		{
			sum = sum + stu[i].score[j];
		}
		stu[i].aver = (float)sum / m;
	}
}
//函数功能：输出n个学生的信息到文件score.txt中
void WritetoFile(STUDENT stu[], int n)
{
	FILE *fp;
	if ((fp = fopen("score.txt","w")) == NULL) //以写方式打开文本文件
	{
		printf("Failure to open student.txt!\n");
		exit(0);
	}
	fwrite(stu, sizeof(STUDENT), n, fp);           //按数据块写文件
	fclose(fp);
}
//函数功能：从文件score.txt中读取学生的信息到结构体数组stu中并返回学生数
int ReadfromFile(STUDENT stu[])
{
	FILE *fp;
	int i;
	if ((fp = fopen("score.txt","r")) == NULL) /* 以读方式打开文本文件 */
	{
		printf("Failure to open student.txt!\n");
		exit(0);
	}
	for (i=0; !feof(fp); i++)
	{
		fread(&stu[i], sizeof(STUDENT), 1, fp); //按数据块读文件
	}
	fclose(fp);
	printf("Total students is %d.\n", i-1);
	return i-1; /* 返回文件中的学生记录数 */
}
//函数功能：显示n个学生的学号、姓名、性别、出生日期、m门课程成绩及平均分
void PrintScore(STUDENT stu[], int n, int m)
{
	for (int i=0; i<n; i++)
	{
		printf("%10ld%8s%3c%6d/%02d/%02d",
		stu[i].studentID, stu[i].studentName, stu[i].stuGender,
		stu[i].birthday.year, stu[i].birthday.month, stu[i].birthday.day);
		for (int j=0; j<m; j++)
		{
			printf("%4d", stu[i].score[j]);
		}
		printf("%6.1f\n", stu[i].aver);
	}
}
//函数功能：对结构体数组stu中的信息按平均分降序排序
void SortScore(STUDENT stu[], int n)
{
	for (int i=0; i<n-1; i++)
	{
	  for (int j=i+1; j<n; j++)
	  {
		if (stu[j].aver > stu[i].aver)
		{
		   SwapStruct(&stu[i], &stu[j]);
		}
	  }
	}
}
//函数功能：交换两个结构体的信息
void SwapStruct(STUDENT *x, STUDENT *y)
{
    STUDENT t;
    t = *x;
    *x = *y;
    *y = t;
}
