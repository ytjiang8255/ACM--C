#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

int main(void)

{
	int N, i = 0, a[10], b[10];
	scanf("%d", &N);
	for (i = 0; i<N; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
	}
	for (i = 0; i<N; i++)
	{
		printf("%d\n", (a[i] + b[i]));
	}
	return 0;
}