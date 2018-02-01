#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

如果存在k个(k>0)课程，该课程具有i个信用CI、SI得分，
那么结果是GPAGPA=（C1*C2*S1+S2+….Ci*SI+….….…)/(C1+C2+….+CI..。..。..)(1<=i<=k，ci!=0)
如果0<=a<Si60，GPA是永远不存在。

第一数字n表示测试例n(n<=50）。在每种情况下，存在一些课程的总数量(K)，
然后接着K行，每个线都会采取这样的形式：
	（课程-名称长度<=30)，(绩点<=10)，(分数<=100)。
	注意：没有空白的名称。所有的输入都合法
如果GPA不存在时，输出：“对不起！”，否则输出值只与GPA被舍入到小数点后2位数。
		存在空行之间两个试验例。
***************************************************
*/
int main()
{
	int N, M, flag=0;
	char C_name[31];
	double Credits[100], Score[100];
	while (scanf("%d", &N) != EOF)
	for (int i = 0; i<N; i++)
	{
		scanf("%d", &M);
		double t1 = 0, t2 = 0;
		flag = 0;		//不能放进循环里面 不然flag永远是0
		for (int j = 0; j<M; j++)
		{
			scanf("%*s%lf%lf", &Credits[j], &Score[j]);
//			scanf("%s%lf%lf", &C_name[j], &Credits[j], &Score[j]);
			if (Score[j] < 60)
			{
				flag = 1;
//				continue;
			}
				t1 += Credits[j] * Score[j];
				t2 += Credits[j];
			
		}
		if (flag == 1)
			printf("Sorry!\n");
		else
			printf("%.2lf\n", t1 / t2);

//		printf(flag ? "Sorry!\n" : "%.2lf\n", t1 / t2);
		if (i<N - 1)
			printf("\n");
	}
	
	return 0;
}