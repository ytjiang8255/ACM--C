#include<stdio.h>
#include<math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告


int prime(int n)
{
	int k;
	k = (int)sqrt(double n);
	for (int j=2;j<=k;j++)
		if (n % j == 0) break;
	if (j > k)
		printf("It's a prime number!\n");
	else printf("It's not prime number!\n");
	return 0;
}

void main()
{
	int i;
	printf("enter a number(int) :\t");
	scanf("%d",&i);
	
	prime(i);
	printf("\t*****End!*****\n");
	
}

