#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
****************************************

输入数据包含多个测试实例，
每个测试实例的第一行是一个整数n（n<100），
表示老师的人数，然后是n个老师的工资。
n=0表示输入的结束，不做处理。
人民币一共有100元、50元、10元、5元、2元和1元六种

****************************************
*/
int main()
{
	int N,a[100],count;
	while(scanf("%d",&N)!=EOF)
	{
		if (N==0)	break;
		for(int i=0;i<N;i++)
			scanf("%d",a);
		for(int j=0;j<N;j++)
		{
			count=0;
			count+=a[i]/100;
			a[i] %=100;
			count +=a[i]/50;
			a[i] %=50;
			count +=a[i]/10;
			a[i] %=10;
			count +=a[i]/5;
			a[i] %=5;
			count +=a[i]/2;
			a[i] %=2;
			count +=a[i];
			
		}
			
		printf("%d\n",count);
	}
	return 0;
}

