#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

int main(void)
{
	int a,b;
	while(scanf("%d%d",&a,&b) != EOF)
	{
		printf("%d\n", (a + b));
		printf("\n");
		
	}
	return 0;
	
}