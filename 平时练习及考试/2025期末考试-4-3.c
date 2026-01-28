# include <stdio.h> 
int main(){
int m,n,i,j;
scanf("%d%d",&m,&n);
int a[m][n];
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
scanf("%d",&a[i][j]);
	}
}
printf("Before:");
for(i=0;i<m;i++){
printf("\n");
	for(j=0;j<n;j++){
printf("%4d",a[i][j]);
	}
}
printf("\nAfter:");
for(j=0;j<n;j++){
printf("\n");
	for(i=0;i<m;i++){
printf("%4d",a[i][j]);
	}
}
return 0;
} 

