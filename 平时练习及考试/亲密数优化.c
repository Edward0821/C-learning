#include<stdio.h>
#include<math.h> 
    /*********Begin*********/
int qms(int num){
	int sum=1;
	int i;
	int sqrt_num=(int)sqrt(num);
	for(i=2;i<=sqrt_num;i++){
		if(num%i==0){
			sum+=i;
			if(i!=num/i){
				sum+=num/i;
			}
		}
	}
	return sum;
	
}
    /*********End**********/
int main(void){
	int a,b;
	for(a=1;a<3001;a++){
		b=qms(a);
		if(a<b&&a==qms(b)){
			printf("(%d,%d)",a,b);
		}
	}
	
	
	
	
    return 0;
}
