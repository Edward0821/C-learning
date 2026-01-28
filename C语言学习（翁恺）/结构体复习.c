#include <stdio.h>
typedef struct Birthday{
int year;
int month;
int day;
}B;
typedef struct Student{
int id;
char *name;
int age;
float score;
B birthday;
}S;
void PrintS(S *stu){
printf("%s-%d-%d-%.2f %d-%d-%d\n",stu->name,stu->id,stu->age,
stu->score,stu->birthday.year,stu->birthday.month,stu->birthday.day);
}
void PrintSs(S *stu,int len){
int i;
for(i=0;i<len;i++){
printf("%s-%d-%d-%.2f %d-%d-%d\n",(stu+i)->name,(stu+i)->id,(stu+i)->age,
(stu+i)->score,(stu+i)->birthday.year,(stu+i)->birthday.month,(stu+i)->birthday.day);}
}
int main(){
S stu1={1001,"DeepSeek",0,100,{2025,02,03}};
S stu2={1002,"Chatgpd",1,100,{2024,01,01}};
printf("%s-%d-%d-%.2f %d-%d-%d\n",stu1.name,stu1.id,stu1.age,
stu1.score,stu1.birthday.year,stu1.birthday.month,stu1.birthday.day);

S students[]={
	{1001,"DeepSeek",0,100,{2025,02,03}},
    {1002,"Chatgpd",1,100,{2024,01,01}}, 
}; 

S *pStu1=&stu1;
S *pStu2=&stu2;

PrintS(pStu1);
PrintS(pStu2);

PrintSs(students,sizeof(students)/sizeof(students[0]));

printf("%d %d\n",sizeof(S),sizeof(B));//结构体内存对齐 
return 0;
}
