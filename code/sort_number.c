#include<stdio.h>
#include<math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

#define N 6  //6个数的排序

int Sort_number(int * array)
{
	int temp,i,j;
	for (i =0;i < N-1;i++)
		for(j =0;j< (N-1)-i;j++)
			if (a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
	
	printf("sort numberis :\t");
	for (i=0;i < N;i++)
		printf("%-3d",a[i]);
	printf("\n");
	return 0;
}


void main()
{
	int a[N],i;
	printf("enter number(int) :\t");
	for (i = 0;i < N;i++)
		scanf("%d",&a[i]);
	for (i = 0;i < N;i++)
		printf("the array :\t");
	
	Sort_number(a);
	
	printf("\t*****End!*****\n");
	
		
	
	
}




 