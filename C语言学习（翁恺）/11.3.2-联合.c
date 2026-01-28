 #include<stdio.h>
union CHI{
unsigned int i;
unsigned char ch[sizeof(int)];
};
int main(void){
union CHI chi;
int i;
chi.i =1234;
for(i=0;i<sizeof(int);i++){
printf("%02hhX ",chi.ch[i]);
} 
return 0;
}
//得到一个整数内部各个字节 
