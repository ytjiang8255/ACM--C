#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
****************************************

有n(n<=100)个整数，
已经按照从小到大顺序排列好，
现在另外给一个整数x，
请将该数插入到序列中，
并使新的序列仍然有序。

****************************************
*/

int main(void)
{
	int N, temp, Insert, Index, a[100];
	while (scanf("%d", &N) != EOF)
	{
		scanf("%d", &Insert);
		if (N == 0 && Insert == 0)	break;
		for (int i = 0; i < N; i++)
			scanf("%d", &a[i]);

		Index = 0;
		for (int j = 0; j<N; j++)
		{
			if (Insert<a[j] && Insert>=a[j - 1])
//				Index = j;
			{
				for (int i = N; i >= j; i--)
					a[i + 1] = a[i];
				a[j]= Insert;
				break;

			}
		}
//		temp = a[Index];
//		a[Index] = Insert;
//		a[Index + 1] = temp;

		for (int j = 0; j<N + 1; j++)
		{
			printf("%d", a[j]);
			if (j<N)
				printf(" ");
		}
		printf("\n");

	}

	
	return 0;
}