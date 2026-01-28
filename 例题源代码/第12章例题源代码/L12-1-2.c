#include  <stdio.h>
typedef struct date
{
	int   year;
	int   month;
	int   day;
}DATE;
typedef struct student
{
	long  studentID;			    /* 学号 */
	char  studentName[10];	    /* 姓名 */
	char  stuGender;			    /* 性别 */
	DATE  birthday;			    /* 出生日期 */
	int	score[4];		         /* 4门课程的成绩 */
}STUDENT;
int main(void)
{
	STUDENT stu1, stu2;
	int i;
	printf("Input a record:\n");
	scanf("%ld", &stu1.studentID);
	scanf("%s", stu1.studentName);  /* 输入学生姓名，无需加& */
	scanf(" %c", &stu1.stuGender); /* %c前有一个空格 */
	scanf("%d", &stu1.birthday.year);
	scanf("%d", &stu1.birthday.month);
	scanf("%d", &stu1.birthday.day);
	for (i=0; i<4; i++)
	{
		scanf("%d", &stu1.score[i]);
	}
	stu2 = stu1;                       /* 同类型的结构体变量之间的赋值操作 */
	printf("&stu2 = %p\n", &stu2); /* 打印结构体变量stu2的地址 */
	printf("%10ld%8s%3c%6d/%02d/%02d%4d%4d%4d%4d\n",
		stu2.studentID, stu2.studentName, stu2.stuGender,
		stu2.birthday.year, stu2.birthday.month, stu2.birthday.day,
		stu2.score[0], stu2.score[1], stu2.score[2], stu2.score[3]);
	return 0;
}
