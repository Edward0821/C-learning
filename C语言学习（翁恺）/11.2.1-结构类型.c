#include<stdio.h>
struct date{
int year;
int month;
int day;
}today,today1;
int main(){
today=(struct date){2025,01,11};
struct date birth={.month=8,.year=2006,.day=21
};
today1=today;
struct date *p=&today;
printf("%p\n",p);
printf("%i-%i-%i\n",today.year,today.month,today.day  );
printf("%i-%i-%i\n",birth.year ,birth.month ,birth.day );
printf("%i-%i-%i",today1.year,today1.month,today1.day  );
return 0;
} 
