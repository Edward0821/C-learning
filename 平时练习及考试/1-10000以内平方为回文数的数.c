# include<stdio.h>
int check(int x);
int main(){
	int num;
    for( num=1;num<=10000;num++){
        if(check(num*num))printf("%d %d\n",num,num*num);
    }
    return 0;
} 
int check(int x){
    int fx=0,t,pd=0;
    t=x;
    while(t!=0){
  fx=fx*10+t%10;
  t/=10;
    }
    if(x==fx)
        pd=1;
    return pd;
}

