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
	STUDENT stu1 = {100310121, "王刚", 'M', {1991,5,19}, {72,83,90,82}};
	STUDENT stu2;
	stu2 = stu1;                     /* 同类型的结构体变量之间的赋值操作 */
	printf("stu2:%10ld%8s%3c%6d/%02d/%02d%4d%4d%4d%4d\n",
		stu2.studentID, stu2.studentName, stu2.stuGender,
		stu2.birthday.year, stu2.birthday.month, stu2.birthday.day,
		stu2.score[0], stu2.score[1], stu2.score[2], stu2.score[3]);
	return 0;
}
