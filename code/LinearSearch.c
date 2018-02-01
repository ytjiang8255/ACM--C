# include <stdio.h> 
# include <string.h> 
# include <stdlib.h> 
#pragma warning(disable: 4996)	//添加的定义排除警告

#define Max 1000		//无需添加分号 ；

int linear_search();
void quick_sort();

int main()
{
	int i, n,  q, sum = 0, key;
	int a[Max + 1];
	while (scanf("%d", &n) == 1)		//当输入非数字时输出不为1 则跳出while循环
	{
		for (i = 0; i<n; i++)
			scanf("%d", &a[i]);
		quick_sort(a,0,n-1);
		for (i = 0; i<n; i++)
			printf("%d  ", a[i]);
		
		printf("\nenter the numbers want to be find : ");
		scanf("%d", &q);
		sum = 0;
		printf("enter the key want to be find : ");
		for (i = 0; i<q; i++)
		{
			
			scanf("%d", &key);
			if (linear_search(a, n, key))	//返回值为1 则执行sum++
			{
				printf("be find : %d\n", key);
				sum++;
			}
				
		}

		printf("sum = %d\n", sum);
		printf("enter q to quit.\n");
	}

	printf("End!\n");
	return 0;
}


/*
	线性搜素函数：		时间复杂度O(n)
	函数列表： 数据存放数组a， 数组长度n， 搜索关键字key
	使用方法：	利用a[i]!=key 返回值为 1
*/
int linear_search(int *a, int n, int key)
{
	int i = 0;
	a[n] = key;
	while (a[i] != key)
		i++;
	return (i != n);

}

/*
	快速排序函数：
	函数列表： 数组首地址*a, 要排序数组起始元素下标low, 要排序数组结束元素下标high
	使用方法：	
*/
void quick_sort(int *a,int a_low,int a_high)
{
	int k, m,n,temp;
	m=a_low;
	n=a_high;
	k=a[(a_low+a_high)/2];			//参照条件
	
	do
	{
		while(a[m]<k && m<a_high)	//从左到右找比k大的数据
			m++;
		while(a[n]>k && n>a_low)	//从右到左找比k小的数据
			n--;
		if(m<=n)				//若找到满足条件的，则交换数据
		{
			temp=a[m];
			a[m]=a[n];
			a[n]=temp;
			m++;
			n--;
		}	
	}while(m<=n);
		if(m<a_high)
			quick_sort(a,m,a_high);		//运用递归方法排序
		if(n>a_low)
			quick_sort(a,a_low,n);
	
}