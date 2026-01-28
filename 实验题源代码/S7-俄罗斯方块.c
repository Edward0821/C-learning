#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#define SCR_WIDTH 680 //屏幕的宽度
#define SCR_HIGH 640  //屏幕的高度
#define DELAY 50      //延时时间

typedef struct ablocks //块的结构体
{
    int x;              //旋转中心的x坐标
    int y;              //旋转中心的y坐标
    int xy[4][2];       //每个方格的坐标
    color_t color;      //每个块的颜色
} BLOCK;
int state[10][21];      //记录每个方格的状态，0表示未填充，1表示已填充
int live = 1;            //标记块是否还活着
long score;               //游戏分数
long totalErasedLines;  //总的消行数
char scoresMsg[50];     //游戏分数信息字符串
char erasedLineMsg[50]; //消行信息字符串

void DrawBlock(BLOCK* blk);
void GenerateBlock(BLOCK* blk, int x, int y, int n);
void MoveBlock(BLOCK* blk, int where);
int JudgeBelow(BLOCK* blk);
int JudgeLeft(BLOCK* blk);
int JudgeRight(BLOCK* blk);
void UpdateState(BLOCK* blk);
void RotateBlock(BLOCK* blk);
void ClearOneLine(int n);
void InitGame(void);
void Output(void);
int main(void)
{
    srand((unsigned)time(NULL));
    setinitmode(0);
    initgraph(SCR_WIDTH, SCR_HIGH);
    Output();
    xyprintf(500, 350, "GAMING...");
    xyprintf(500, 450, "Directiion key to move");
    xyprintf(500, 500, "Space key to pause");
    setfillcolor(EGERGB(255, 0, 0));
setcolor(EGERGB(80, 80, 80));
//画方格
    for (int i=140+20; i<540; i=i+20)   
    {
        line(140, i, 340, i);
    }
    for (int i=140+20; i<340; i=i+20)
    {
        line(i, 140, i, 540);
    }
    setcolor(EGERGB(180, 180, 180));
    rectangle(140, 140, 140+200+1, 140+400+1);
    BLOCK testBlock;
    BLOCK nextBlock;
    int rk1 = 1 + rand() % 7;         //随机产生1到7
    for (int x=0; x<10; x++)
    {
        state[x][20] = 1;
    }
    for (int n=0; ;Sleep(10),n++)    //主循环
    {
        if (live == 1)
        {
            live = 0;
            testBlock.x = 241 + 10 - 20;     //生成当前块
            testBlock.y = 161 + 10 - 20;
            nextBlock.x = 500 + 10;   //生成下一个块
            nextBlock.y = 100 + 10;
            GenerateBlock(&testBlock, testBlock.x, testBlock.y, rk1);
            rk1 = 1 + rand() % 7;
            GenerateBlock(&nextBlock, nextBlock.x, nextBlock.y, rk1);
            DrawBlock(&testBlock);
            setfillcolor(BLACK);
            bar(400, 50, 600, 150);
            DrawBlock(&nextBlock);
        }
        key_msg whatfx;
        if (kbmsg())           //检测是否有键盘操作消息
        {
            whatfx = getkey(); //获取按键消息
            if (whatfx.msg == key_msg_down)//若有键盘按下的消息
            {
                if (whatfx.key == VK_SPACE)//按空格暂停
                {
                    setfillcolor(BLACK);
                    bar(500, 350, 500+100, 380);
                    xyprintf(500, 350, "PAUSE... ");
                    getch();
                    getch();
                    bar(500, 350, 500+100, 380);
                    xyprintf(500, 350, "GAMING... ");
                }
                color_t temp = testBlock.color;    //清除当前块，因为要改变形状
                testBlock.color = BLACK;
                DrawBlock(&testBlock);
                testBlock.color = temp;
                if (whatfx.key == VK_LEFT && JudgeLeft(&testBlock) != 1)
                {
                    if (testBlock.xy[0][0]>=161&&testBlock.xy[1][0]>=161
&&testBlock.xy[2][0]>=161&&testBlock.xy[3][0]>=161)
                    {
                        MoveBlock(&testBlock, 3);
                    }
                }
                if (whatfx.key == VK_RIGHT && JudgeRight(&testBlock) != 1)
                {
                    if (testBlock.xy[0][0]<=301&&testBlock.xy[1][0]<=301
&&testBlock.xy[2][0]<=301&&testBlock.xy[3][0]<=301)
                    {
                        MoveBlock(&testBlock, 4);
                    }
                }
                if (whatfx.key == VK_DOWN)
                {
                    n = DELAY;
                }
                if (whatfx.key == VK_UP)
                {
                    RotateBlock(&testBlock);
                }
                DrawBlock(&testBlock);                 //绘制旋转后的块
            }
        }
        if (n == DELAY)                                //处理自由下落
        {
            n = 0;
            if (JudgeBelow(&testBlock) == 1)               //若已经碰撞
            {
                UpdateState(&testBlock);                   //则更新方格状态
                //game over判定
                if (testBlock.xy[0][1]<141||testBlock.xy[1][1]<141
||testBlock.xy[2][1]<141||testBlock.xy[3][1]<141)
                {
                    xyprintf(500,350,"GAME OVER !");
                    getch();
                    setfillcolor(BLACK);
                    bar(500, 350, 500+100, 380);
                    xyprintf(500, 350, "GAMING... ");
                    InitGame();
                }
                live = 1;
                continue;
            }
            color_t temp = testBlock.color;      //清除当前块整体下移后显示
            testBlock.color = BLACK;
            DrawBlock(&testBlock);
            testBlock.color = temp;
            MoveBlock(&testBlock, 1);
            DrawBlock(&testBlock);
        }
    }
    getch();
    closegraph();
    return 0;
}
//函数功能：根据旋转中心和类型（n,共七种）生成一个块
void GenerateBlock(BLOCK* blk, int x, int y, int n)
{
    x -= 10;
    y -= 10;
    switch (n)
    {
    case 1:
        //L
        blk->xy[0][0] = x - 20;
        blk->xy[0][1] = y - 20;
        blk->xy[1][0] = x - 20;
        blk->xy[1][1] = y;
        blk->xy[2][0] = x;
        blk->xy[2][1] = y;
        blk->xy[3][0] = x + 20;
        blk->xy[3][1] = y;
        blk->color = 0xFFA500;
        break;
    case 2:
        //S
        blk->xy[0][0] = x - 20;
        blk->xy[0][1] = y;
        blk->xy[1][0] = x;
        blk->xy[1][1] = y;
        blk->xy[2][0] = x;
        blk->xy[2][1] = y - 20;
        blk->xy[3][0] = x + 20;
        blk->xy[3][1] = y - 20;
        blk->color = 0x00ff00;
        break;
    case 3:
        //一
        blk->xy[0][0] = x - 40;
        blk->xy[0][1] = y - 20;
        blk->xy[1][0] = x - 20;
        blk->xy[1][1] = y - 20;
        blk->xy[2][0] = x;
        blk->xy[2][1] = y - 20;
        blk->xy[3][0] = x + 20;
        blk->xy[3][1] = y - 20;
        blk->x -= 10;
        blk->y -= 10;
        blk->color = 0x00ffff;
        break;
    case 4:
        //J
        blk->xy[0][0] = x - 20;
        blk->xy[0][1] = y;
        blk->xy[1][0] = x;
        blk->xy[1][1] = y;
        blk->xy[2][0] = x + 20;
        blk->xy[2][1] = y;
        blk->xy[3][0] = x + 20;
        blk->xy[3][1] = y - 20;
        blk->color = 0x0000ee;
        break;
    case 5:
        //田
        blk->xy[0][0] = x - 20;
        blk->xy[0][1] = y - 20;
        blk->xy[1][0] = x;
        blk->xy[1][1] = y - 20;
        blk->xy[2][0] = x - 20;
        blk->xy[2][1] = y;
        blk->xy[3][0] = x;
        blk->xy[3][1] = y;
        blk->x -= 10;
        blk->y -= 10;
        blk->color = YELLOW;
        break;
    case 6:
        //T
        blk->xy[0][0] = x - 20;
        blk->xy[0][1] = y;
        blk->xy[1][0] = x;
        blk->xy[1][1] = y;
        blk->xy[2][0] = x;
        blk->xy[2][1] = y - 20;
        blk->xy[3][0] = x + 20;
        blk->xy[3][1] = y;
        blk->color = 0xff00ff;
        break;
    case 7:
        //Z
        blk->xy[0][0] = x - 20;
        blk->xy[0][1] = y - 20;
        blk->xy[1][0] = x;
        blk->xy[1][1] = y - 20;
        blk->xy[2][0] = x;
        blk->xy[2][1] = y;
        blk->xy[3][0] = x + 20;
        blk->xy[3][1] = y;
        blk->color = 0xff0000;
        break;
    }
}
//函数功能：绘制一个块
void DrawBlock(BLOCK* blk)
{
    setfillcolor(blk->color);
    if (blk->x > 400)
    {
        bar(blk->xy[0][0], blk->xy[0][1],
blk->xy[0][0]+19, blk->xy[0][1]+19);
        bar(blk->xy[1][0], blk->xy[1][1],
blk->xy[1][0]+19, blk->xy[1][1]+19);
        bar(blk->xy[2][0], blk->xy[2][1],
blk->xy[2][0]+19, blk->xy[2][1]+19);
        bar(blk->xy[3][0], blk->xy[3][1],
blk->xy[3][0]+19, blk->xy[3][1]+19);
    }
    else//不要超出方格
    {
        if (blk->xy[0][1] >= 141)
        {
            bar(blk->xy[0][0], blk->xy[0][1],
blk->xy[0][0]+19, blk->xy[0][1]+19);
        }
        if (blk->xy[1][1] >= 141)
        {
            bar(blk->xy[1][0], blk->xy[1][1],
blk->xy[1][0]+19, blk->xy[1][1]+19);
        }
        if (blk->xy[2][1] >= 141)
        {
            bar(blk->xy[2][0], blk->xy[2][1],
blk->xy[2][0]+19, blk->xy[2][1]+19);
        }
        if (blk->xy[3][1] >= 141)
        {
            bar(blk->xy[3][0], blk->xy[3][1],
blk->xy[3][0]+19, blk->xy[3][1]+19);
        }
    }
}
//函数功能：块移动
void MoveBlock(BLOCK* blk, int where)
{
    switch (where)
    {
    case 1://下
        blk->xy[0][1] += 20;
        blk->xy[1][1] += 20;
        blk->xy[2][1] += 20;
        blk->xy[3][1] += 20;
        blk->y+=20;
        break;
    case 3://左
        blk->xy[0][0] -= 20;
        blk->xy[1][0] -= 20;
        blk->xy[2][0] -= 20;
        blk->xy[3][0] -= 20;
        blk->x -= 20;
        break;
    case 4://右
        blk->xy[0][0] += 20;
        blk->xy[1][0] += 20;
        blk->xy[2][0] += 20;
        blk->xy[3][0] += 20;
        blk->x += 20;
        break;
    }
}
//函数功能：清除一行
void ClearOneLine(int n)
{
    setfillcolor(EGERGB(0, 0, 0));
    for (int k=0; k<=10; k++)
    {
        bar(20*k+141, 141+20*n, 20*k+141+19, 141+20*n+19);
    }
}
//函数功能：块状态更新
void UpdateState(BLOCK* block)
{
    int erasedLines = 0;//消行数初始化
    for (int x=0; x<4; x++)
    {
        state[(block->xy[x][0]-141)/20][(block->xy[x][1]-141)/20] = 1;
    }
    for (int x=0; x<10; x++)
    {
        state[x][20] = 1;
    }
    for (int i=0; i<20; i++)
    {
        int j;
        for (j=0; j<10; j++)
        {
            if (state[j][i] == 0)
            {
                break;
            }
        }
        if (j == 10)            //若一行全部被填充
        {
            ClearOneLine(i);    //消除这一行
            totalErasedLines++; //总消行数计数1次
            erasedLines++;      //记录当前的消行数
            for (int down=i-1; down>0; down--)   //逐层下移
            {
                for (int k=0; k<10; k++)
                {
                    if (state[k][down] == 1)
                    {
                        //获取像素颜色并设置填充色
                        color_t c = getpixel(k*20+141+10, 10+down*20+141); 
                        setfillcolor(EGERGB(0, 0, 0));
                        bar(k*20+141, down*20+141, 
k*20+141+19, down*20+141+19);
                        //为了下移后可以保持颜色不变,使用上一块颜色填充下一块
setfillcolor(c); 
                        bar(k*20+141, 20+down*20+141, 
k*20+141+19, 20+down*20+141+19);
                    }
                    state[k][down+1] = state[k][down];  //下移
                }
            }
        }
    }
    //一次消掉的行数越多，则分数越高
    if (erasedLines == 1) score += 1;
    if (erasedLines == 2) score += 3;
    if (erasedLines == 3) score += 5;
    if (erasedLines == 4) score += 8;
    Output();
}
//函数功能：判断块下方是否有障碍，有障碍返回1，否则返回0
int JudgeBelow(BLOCK* blk)
{
    for (int x=0; x<4; x++)
    {
        if (state[(blk->xy[x][0]-141)/20][(blk->xy[x][1]-141)/20+1] == 1)
        {
            return 1;
        }
    }
    return 0;
}
//函数功能：判断左方是否有障碍，有障碍返回1，否则返回0
int JudgeLeft(BLOCK *blk)
{
    for (int x=0; x<4; x++)
    {
        if (state[(blk->xy[x][0]-141)/20-1][(blk->xy[x][1]-141)/20] == 1)
        {
            return 1;

        }
    }
    return 0;
}
//函数功能：判断右方是否有障碍，有障碍返回1，否则返回0
int JudgeRight(BLOCK *blk)
{
    for (int x=0; x<4; x++)
    {
        if (state[(blk->xy[x][0]-141)/20+1][(blk->xy[x][1]-141)/20] == 1)
        {
            return 1;
        }
    }
    return 0;
}
//函数功能：旋转块
void RotateBlock(BLOCK* blk)
{
    int x1 = blk->x, y1 = blk->y;

    for (int i=0; i<4; i++)  //如果旋转之后导致重叠或超出方格,则不旋转
    {
        if ((x1-(blk->xy[i][1]-y1)-20 > 321)
||(x1-(blk->xy[i][1]-y1)-20 < 141))
        {
            return;
        }
        if (state[((x1-(blk->xy[i][1]-y1)-20)-141)/20]
[(y1+blk->xy[i][0]-x1-141)/20] == 1)
        {
            return;
        }
    }
    for (int i=0; i<4; i++)//顺时针旋转90度的坐标处理
    {
        int temp_xz = blk->xy[i][0];
        blk->xy[i][0] = x1 - ((blk->xy[i][1]) - y1) - 20;
        blk->xy[i][1] = y1 + temp_xz - x1;
    }
}
//函数功能：游戏初始化
void InitGame(void)
{
    for (int x=0; x<10; x++)//超出方格的一行置1,为了统一判断是否碰撞
    {
        state[x][20] = 1;
    }
    for (int i=0; i<20; i++)
    {
        for (int j=0; j<10; j++)
        {
            state[j][i] = 0; //状态清零
        }
        ClearOneLine(i);     //清除整个行
    }
    score = 0;               //总游戏分数清零
    totalErasedLines = 0; //总消行数清零
}
//函数功能：输出信息
void Output(void)
{
    sprintf(scoresMsg, "Score: %ld", score);
    sprintf(erasedLineMsg, "Kill: %ld", totalErasedLines);
    xyprintf(500, 250, scoresMsg);
    xyprintf(500, 280, erasedLineMsg);
}
