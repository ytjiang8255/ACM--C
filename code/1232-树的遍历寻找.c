#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/**
测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，分别是城镇数目N ( < 1000 )和道路数目M；
随后的M行对应M条道路，每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。为简单起见，城镇从1到N编号。 
注意:两个城市之间可以有多条道路相通,也就是说
3 3
1 2
1 2
2 1
这种输入也是合法的
当N为0时，输入结束，该用例不被处理。 


对每个测试用例，在1行里输出最少还需要建设的道路数目
4 2
1 3
4 3

>>>1

3 3
1 2
1 3
2 3

>>>0

5 2
1 2
3 5

>>>2

999 0

>>>998

0
**/
int bin[1002];			//数组下标过大时应该将数组从局部变量（分配在栈里）定义为全局变量（分配在堆里）
void merge(int x,int y);
int findx(int x);

int main()
{
    int n,m,i,x,y,count;
    while(scanf("%d",&n) && n)		//当n输入0后不执行程序，退出
    {
        for(i=1;i<=n;i++)
            bin[i] = i;
        for(scanf("%d",&m);m>0;m--)	//可以for里面输入需要循环的数值，利用递减的方式来执行程序块
        {
            scanf("%d %d",&x,&y);
            merge(x,y);
        }
        for(count=-1, i=1;i<=n;i++)
            if(bin[i] == i)
                count ++;
        printf("%d\n",count);
    }
	return 0;
}



int findx(int x)
{
    int r=x;
    while(bin[r] !=r)
        r=bin[r];
    return r;
}



void merge(int x,int y)
{
    int fx,fy;
    fx = findx(x);
    fy = findx(y);
    if(fx != fy)
        bin[fx] = fy;
}