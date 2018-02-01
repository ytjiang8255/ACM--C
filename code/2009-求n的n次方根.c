#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
	*************************************************************
	数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和。
	************************************************************

*/
int main(void)
{
	int i,  N;
	double M, Root;
	while (scanf("%lf%d", &M, &N) != EOF)
	{

		Root = 0;
		for (i = 0; i<N; i++)
		{
			Root += M;
			M = sqrt(M);
		}
		printf("%.2lf\n", Root);

	}
	return 0;

}