#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
****************************************

假设一个班有n(n<=50)个学生，
每人考m(m<=5)门课，
求每个学生的平均成绩和每门课的平均成绩，
并输出各科成绩均大于等于平均成绩的学生数量。

****************************************
*/
int main()
{
	int n, m ;
	double score[50][5];		//!!!!!CAM编译居然float型不能通过
	while (scanf("%d%d", &n,&m) != EOF && n<=50 && m<=5)
	{
		double sum1 = 0, sum2 = 0, aver_M[50], aver_L[50];
		if (n == 0 && m == 0)	break;
		for (int i = 0; i < n; i++)
		{
			sum1 = 0;
			for (int j = 0; j<m; j++)
			{

				scanf("%lf", &score[i][j]);
				sum1 += score[i][j];	//个人总成绩
				aver_M[i] = sum1 / m;	//平均成绩会叠加
			}
		}
	
/*		for (int i = 0; i<n; i++)
		{
			sum1 = 0;
			for (int j = 0; j<m; j++)
				sum1 += score[i][j];		//单科总成绩
			aver_M[i] = sum1 / m;
		}
*/
		for (int j = 0; j<m; j++)
		{
			sum2 = 0;
			for (int i = 0; i<n; i++)
				sum2 += score[i][j];		//单科总成绩
			aver_L[j] = sum2 / n;
		}

		int flag, count = 0;
		for (int i = 0; i<n; i++)
		{
			flag = 1;			//flag赋值为1
			for (int j = 0; j < m; j++)
			if(score[i][j]<aver_L[j])
			{
				flag = 0;	break;
			}
			if (flag)
				count += 1;
		}

		//输出个人平均成绩
		for (int i = 0; i<n; i++)
		{
			printf("%.2lf", aver_M[i]);
			if (i<n - 1)
				printf(" ");
		}
		printf("\n");

		//输出单科成绩
		for (int j = 0; j<m; j++)
		{
			printf("%.2lf", aver_L[j]);
			if (j<m - 1)
				printf(" ");
		}
		printf("\n");
		//输出及格人数,以及空一行
		printf("%d\n\n", count);
	}

	return 0;
}