#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
四位数2992，这个数，它的十进制数表示，其四位数字之和为2+9+9+2=22，
它的十六进制数BB0，其四位数字之和也为22，同时它的十二进制数表示1894，其四位数字之和也为22

输入含有一些四位正整数，如果为0，则输入结束。
若n为Sky数，则输出“#n is a Sky Number.”，否则输出“#n is not a Sky Number.”。
每个结果占一行。注意：#n表示所读入的n值。
**/

int Transition(int num,int scale);
int main()
{
	int n,t1,t2,t3;
	while(scanf("%d",&n)==1 && n)
	{
		t1=Transition(n,10);
		t2=Transition(n,16);
		t3=Transition(n,12);
	//	printf("%d\n",t1);
		if((t1==t2)&&(t2==t3))
			printf("%d is a Sky Number.\n",n);
		else 
			printf("%d is not a Sky Number.\n",n);
		
	}
	return 0;
}

int Transition(int num,int scale)
{
	int sum=0;
	while(num)
	{
		sum+=num % scale;	//将数进行进制转换后的有效位加起来
		num /= scale;		//相当于整数右移一个进制位
	}
	return sum;
}