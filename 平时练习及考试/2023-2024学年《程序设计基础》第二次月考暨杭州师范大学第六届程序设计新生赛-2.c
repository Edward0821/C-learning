#include<stdio.h>
int main(){
int n,i,s=0;
scanf("%d",&n);
int h[n];
for(i=0;i<n;i++){
	scanf("%d",&h[i]);
} 
for(i=0;i<n;i++){
if(3<=i+1&&i+1<=n-2&&h[i-2]<h[i-1]&&h[i-1]<h[i]&&h[i+2]<h[i+1]&&h[i+1]<h[i])
s++;
}
printf("%d",s);
return 0;
}
