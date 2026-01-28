# include <stdio.h> 
int main(){
double kg,m,p;
scanf("%lf%lf",&kg,&m);
p=kg/(m*m);
printf("%.1f",p);
if(p>25)
printf("PANG");
else
printf("Hai Xing");
} 
