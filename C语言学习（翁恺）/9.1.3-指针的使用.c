#include<stdio.h>
//找出一个数组的最大值和最小值 
void minmax(int *a,int len,int *min,int *max);
int main(){
int n,i;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++){
scanf("%d",&a[i]); 
}
int min,max;
minmax(a,sizeof(a)/sizeof(a[0]),&min,&max);
printf("min=%d,max=%d",min,max);
return 0;
}
void minmax(int *a,int len,int *min,int *max){
int i;
*min=*max=a[0];
for(i=1;i<len;i++){
if(a[i]<*min){
*min=a[i];
}
if(a[i]>*max){
*max=a[i]; 
}
}
}
