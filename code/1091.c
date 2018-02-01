#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

int main(void)

{
	int   a, b;
	while (scanf("%d%d", &a, &b) != EOF  && (a != 0 || b != 0))
	{
			printf("%d\n", (a + b));
	}
	return 0;
}