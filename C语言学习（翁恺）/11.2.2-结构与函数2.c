#include<stdio.h>
struct d{
int x;
int y;
}y;
struct d* get(struct d *y){
	scanf("%d",&y->x);
	scanf("%d",&y->y);
	printf("%i  %i\n",y->x ,y->y );
}
/*struct d get(void){
struct d p;
scanf("%d%d",&p.x ,&p.y );
return p;
}
int main(){
y=(struct d){0,0};
y=get();
printf("%i  %i",y.x ,y.y );
return 0;
}
*/
int main(){
y=(struct d){0,0};
get(&y);
printf("%i  %i",y.x ,y.y );
return 0;
}

