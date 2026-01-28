# include <stdio.h> 
void Sort(int a[],int n){
	int i,j,k,t;
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[k]){
				k=j;
			}
		}
		if(k!=i){
	  t=a[k];
	  a[k]=a[i];
	  a[i]=t;
        }
        	for(i=0;i<n-1;i++){
            printf("%d ",a[i]);
			}
			printf("%d",a[n-1]);
	}
}
int main(){
int n,j;
scanf("%d",&n);
int s[n];
for(j=0;j<n;j++){
scanf("%d",&s[j]);
}
Sort(s,n);
return 0;
} 

