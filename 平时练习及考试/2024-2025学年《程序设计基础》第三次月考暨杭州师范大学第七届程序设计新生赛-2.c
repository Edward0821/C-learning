#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	if(n%7==0)
	printf("hello world.");
	else if(n%7!=0&&n%2==0)
	printf("if you don't walk out, you will think that this is the whole world.");
	else if(n%7!=0&&n%2!=0&&n%5==0)
	printf("life isn't like in the movies.life is much harder.");
	else 
	printf("right now the paradiso needs you and you need the paradiso.");
	return 0;
}
