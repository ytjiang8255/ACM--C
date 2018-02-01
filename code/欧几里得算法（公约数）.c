#include <stdio.h>

int GCD(int x, int y)
{
	int temp;
	if (x < y)
	{
		temp = x;
		x = y;
		y = temp;
	}
	while (y != 0)
	{
		temp = x%y;			// printf("%d\t", temp);
		x = y;
		y = temp;
	}
	
	return (x);
}

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		int c = GCD(a, b);
		printf("the gcd = %d\n", c);
		printf("the lcd = %d\n",a*b/c);
	}

	return 0;
}