#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
	****************************************************
					输入数字，取绝对值。
	****************************************************

*/
int main(void)
{
	double i;
	if (i<0)
	{
		i= -i;
		printf("%.2lf",i);
	}
	else 
		printf("%.2lf",i);
	return 0;
}


