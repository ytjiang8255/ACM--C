#include <stdio.h>

int main(void)

{
	
	int a, b;
//	while(scanf("%d%d", &a, &b) != EOF)//需要多次输入
//	while (~scanf("%d%d", &a, &b))
	while(scanf("%d%d", &a, &b) == 2)

	{
		printf("%d\n", (a + b));
	}
	return 0;
}