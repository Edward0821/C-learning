#include<stdio.h>
void swap(int*a,int*b){
int t=*a;
*a=*b;
*b=t;
}
void d(int *a,int k,int l,int r){
int i,j;
if(k==1){
for(i=l;i<r;i++){
for(j=l;j<r-i+l;j++){
if(a[j]>a[j+1]){
swap(&a[j],&a[j+1]);
}
}}}
if(k==2){
for(i=l;i<r;i++){
for(j=l;j<r-i+l;j++){
if(a[j]<a[j+1]){
swap(&a[j],&a[j+1]);
}
}
}
}
}
int main(){
int n,t;
scanf("%d",&n);
int a[n],i;
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
scanf("%d",&t);
    int k,b,j;
for(i=0;i<t;i++){
scanf("%d%d%d",&k,&b,&j);
d(a,k,b-1,j-1);
}
    for(i=0;i<n;i++){
printf(" %d",a[i]);
}
    return 0;
}
