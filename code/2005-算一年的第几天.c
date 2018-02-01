#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
	*************************************************************
				输入年月日，求出这天是这一年的第几天。
	************************************************************

*/
int main(void)
{
	int year,month,day,sum;
//	while (scanf("%d%d%d",&year,&month,&day) != EOF)
	while (scanf("%d%*c%d%*c%d", &year, &month, &day) != EOF)	//1985/1/20输入格式要求-->靠%*c跳过处理
	{
		int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		int b[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
		if (year % 400 ==0 || (year % 4==0 && year %100 != 0))
		{
			sum=0;
			for (int i=0;i<month-1;i++)
			{
				sum += b[i];
				sum += day;	
			}
			printf("%d\n",sum);
		}
		else {
			sum=0;
			for (int i=0;i<month-1;i++)
			{
				sum += a[i];
				sum += day;
			}
			printf("%d\n",sum);
		}
	}
	
	return 0;
}

