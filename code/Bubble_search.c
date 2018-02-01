# include <stdio.h> 
# include <string.h> 
# include <stdlib.h> 
#pragma warning(disable: 4996)	//添加的定义排除警告

#define Max 1000		//无需添加分号 ；

int bubble_search();
void quick_sort(int *a,int a_low,int a_high);


int main()
{
	int i, n,  q, sum = 0, key;
	int a[Max + 1];
	while (scanf("%d", &n) == 1)		//当输入非数字时输出不为1 则跳出while循环
	{
		for (i = 0; i<n; i++)
			scanf("%d", &a[i]);

		quick_sort(a, 0, n-1);			//切记quick排序的规则，所需排序的下标编号 从小到大
		for (i = 0; i<n; i++)
			printf("%d  ", a[i]);

		
		printf("enter the numbers want to be find : ");
		scanf("%d", &q);
		sum = 0;
		printf("enter the key want to be find : ");
		for (i = 0; i<q; i++)
		{
			
			scanf("%d", &key);
			if (bubble_search(a,n, key))	//返回值为1 则执行sum++
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
	冒泡搜索函数： 		时间复杂度O(n)
	函数列表： 数组首地址*a, 要排序数组元素个数n，关键元素key
	使用方法：	从数据结构线形表的一端开始，顺序扫描，
				依次将扫描到的结点关键字与给定值k相比较，若相等则表示查找成功；
				若扫描结束仍没有找到关键字等于k的结点，表示查找失败
*/
int bubble_search(int a,int n,int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
			return 1;
	}
	return -1;
}




/*
	冒泡排序函数：
	函数列表： 数组首地址*a, 要排序数组元素个数
	使用方法：	从a[0]元素开始依次将其和后面的元素比较，类似遍历排序
*/
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