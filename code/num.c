#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#pragma warning(disable: 4996)	//添加的定义排除警告


/*
int i=0,n;
scanf("%d",n);		//限定输入的个数
while( i < n)		//用enter键确认输入时，当超过限定数则会终止输入
{
	scanf("%d",&a[i]);
	i++;
}
*/

//argc表示参数个数，包括执行文件名.argv存放参数，包括执行文件名
int MIN(int x,int y)
{
	int min;
	if(x >y)
	{
		min = y;
	}
	else min = x;
	
	return min;
}
int main(int argc,char **argv)
{
	int m,n,temp,min,i;
	printf("input two number :\n");
	scanf("%d%d",&m,&n);
	
	min = MIN(m,n);
	for(i = min;i > 0;i--)
		if(m % i==0 && n % i==0)
			printf("the greatest common divisor is :%d",i);
	
	for (i = 1;i < m;i++)
		if (n*i % m ==0 )
			printf("the lease common multiple is :%d",n*i);

	return 0;
}		


