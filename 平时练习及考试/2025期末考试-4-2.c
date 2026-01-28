# include <stdio.h> 
int main(){
int n,i,f,a=0,b=0,c=0;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&f);
if (f>=85)
a++;
else if(f<60)
c++;
else
b++;
}
printf("%d %d %d",a,b,c);
return 0;
} 
