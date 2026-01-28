#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
typedef struct card
{
	char  suit[10];
	char  face[10];
}CARD;
void Deal(CARD *wCard);
void Shuffle(CARD *wCard);
void FillCard(CARD wCard[], char *wFace[], char *wSuit[]);
int main(void)
{
	char *suit[] = {"Spades","Hearts","Clubs","Diamonds"};
	char *face[] = {"A","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
	CARD card[52];
	srand (time(NULL));
	FillCard(card, face, suit);
	Shuffle(card);
	Deal(card);
	return 0;
}
/*	函数功能：花色按黑桃、红桃、草花、方块的顺序，面值按A~K的顺序，排列52张牌 */
void  FillCard(CARD wCard[], char *wFace[], char *wSuit[])
{
	int	i;
	for (i=0; i<52; i++)
	{
		strcpy(wCard[i].suit, wSuit[i/13]);
		strcpy(wCard[i].face, wFace[i%13]);
	}
}
/*	函数功能：将52张牌的顺序打乱以模拟洗牌过程 */
void Shuffle(CARD *wCard)
{
	int i, j;
	CARD temp;
	for (i=0; i<52; i++) /*每次循环产生一个随机数，交换当前牌与随机数指示的牌*/
	{
		j = rand()%52;     /* 每次循环产生一个0~51的随机数 */
		temp = wCard[i];
		wCard[i] = wCard[j];
		wCard[j] = temp;
	}
}
/* 	函数功能：输出每张牌的花色和面值以模拟发牌过程 */
void Deal(CARD *wCard)
{
	int i;
	for (i=0; i<52; i++)
	{
		printf("%9s%9s%c",wCard[i].suit,wCard[i].face,i%2==0?'\n':'\t');
	}
	printf("\n");
}
