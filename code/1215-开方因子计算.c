#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告



int main()
{
	int i, j, N, sum, num;
	while (scanf("%d", &N) != EOF && N!=0)
	{
		for (i = 0; i < N; i++)
		{
			sum = 1;
			scanf("%d", &num);
			if (num == 1)
				sum = 0;
			else
			{
/*				for (i = 2; i*i < num; i++)
				{
					if (num%i == 0)
						sum = i + num / i + sum;
				}
				if ((i - 1)*(i - 1) == num	//若是完全平方数 减去一个开方因子  
					sum = sum - i + 1;
*/
				for (i = 2; i <= (int)sqrt((double)num);i++)
				if (num%i == 0)
					sum = sum + i + num / i;
				if ((i - 1)*(i - 1) == num)
					sum = sum - i + 1;
			}
			printf("%d\n", sum);
		}

	}
	
	return 0;
}
