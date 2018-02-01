#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
*************************************************************
对于表达式n^2+n+41，当n在（x,y）范围内取整数值时（包括x,y）(-39<=x<y<=50)，判定该表达式的值是否都为素数。
输入数据有多组，每组占一行，由两个整数x，y组成，当x=0,y=0时，表示输入结束，该行不做处理。
对于每个给定范围内的取值，如果表达式的值都为素数，则输出"OK",否则请输出“Sorry”,每组输出占一行。
0 1
0 0
-------
OK

*************************************************************
*/

int IsPrime(int num);
int main(void)
{
	int x,y,i,temp,count;
	while(scanf("%d%d",&x,&y)!=EOF && (x||y))
	{
		count=0;
		if(x>y)
		{
			temp=x;
			x=y;
			y=temp;
		}
		for(i=x;i<=y;i++)
		{
			temp=i*i+i+41;
			if(IsPrime(temp))
				count++;
			temp=0;
		}
//		if(count==(y-x))	//两个数的差值个数= y-x+1
		if(count > (y-x))
			printf("OK\n");
		else
			printf("Sorry\n");
		
	}
	return 0;
}
	
int IsPrime(int num)		//素数判定函数，如果是返回值为1，不是则为0
{
	int i;
	for(i=2;i<=num/2;i++)	//从2开始的半值循环判定，一旦有能被整除的数则返回值为0
	if(num%i==0)
		return 0;
	return 1;
	
}