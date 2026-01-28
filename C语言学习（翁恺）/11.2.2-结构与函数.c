#include<stdio.h>
#include<stdbool.h>
struct date{
int year;
int month;
int day;
};
bool isLeap(struct date d);
int nod(struct date d);
int main(){
struct date today,tomorrow;
printf("输入今天的日期：____年___月___日");
scanf("%i%i%i",&today.year,&today.month ,&today.day );
//printf("%i-%i-%i\n",today.year,today.month,today.day  );
if(today.day!=nod(today)){
tomorrow.day =today.day +1;
tomorrow.month=today.month ;
tomorrow.year =today.year ;
}
else if(today.month==12){
tomorrow.day =1;
tomorrow.month=1 ;
tomorrow.year =today.year+1;
}
else{
tomorrow.day = 1;
tomorrow.month=today.month+1 ;
tomorrow.year =today.year ;
}
printf("明天是%i年%i月%i日",tomorrow.year ,tomorrow.month ,tomorrow.day );
return 0;
}
int nod(struct date d){
int days;
const int dpm[12]={31,28,31,30,31,30,31,31,30,31,30,31};
if(d.month ==2&&isLeap(d))
days=29;
else
days=dpm[d.month -1];
return days;
}
bool isLeap(struct date d){
bool leap=false;
if((d.year%4==0&&d.year %100!=0)||d.year %400==0)
leap=true;
return leap;
}

