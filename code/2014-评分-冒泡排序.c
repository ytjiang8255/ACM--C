#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

void bubble_sort(int *a,int n);
int main(int argc, char *argv[])
{
	int n;
//	float  a[20], sum = 0, average = 0,temp;	//数组范围溢出了
	float  a[20], sum = 0, average = 0,temp;
	while (scanf("%d", &n) != EOF)
	{
		if (n > 2 && n <= 100)
		{
			int i, j; 
			average = 0;
			sum = 0;
			for (int i = 0; i<n; i++)
				scanf("%f", &a[i]);
		
			bubble_sort(a,n);
			for (i = 1; i < n - 1; i++)
//				printf("%d", a[i]);
				sum += a[i];
			
		}
		average = sum / (n - 2);
		printf("%.2f\n", average);
		
	}
	return 0;
}

void bubble_sort(int *a,int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}	
}