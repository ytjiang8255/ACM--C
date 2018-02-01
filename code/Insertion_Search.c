# include <stdio.h> 
# include <string.h> 
# include <stdlib.h> 
#pragma warning(disable: 4996)	//添加的定义排除警告

#define Max 1000		//无需添加分号 ；

int insertion_search();
void chiose_sort();
int main()
{
	int i, n,  q, sum = 0, key;
	int a[Max + 1];
	while (scanf("%d", &n) == 1)		//当输入非数字时输出不为1 则跳出while循环
	{
		for (i = 0; i<n; i++)
			scanf("%d", &a[i]);

		chiose_sort(a, n);			//切记quick排序的规则，所需排序的下标编号 从小到大
		for (i = 0; i<n; i++)
			printf("%d  ", a[i]);
		
		
		printf("enter the numbers want to be find : ");
		scanf("%d", &q);
		sum = 0;				//sum赋值可以避免错误
		printf("enter the key want to be find : ");
		for (i = 0; i<q; i++)
		{
//			sum = 0;		//循环sum 每次只能重新从0 开始计算
			scanf("%d", &key);
			if (insertion_search(a,key,0,n-1))	//返回值为1 则执行sum++
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
	插值搜素函数：		时间复杂度 O(log (log n))
	函数列表： 数据存放的数组， 搜索的关键字， 数组下标最小值，数组下标最大值
	使用方法：	基于二分查找算法，将查找点的选择改进为自适应选择，可以提高查找效率
	注意事项：	对于表长较大，而关键字分布又比较均匀的查找表来说，插值查找算法的平均性能比折半查找要好的多。
				反之，数组中如果分布非常不均匀，那么插值查找未必是很合适的选择。
*/
int insertion_search(int *a,int key,int a_low,int a_high)
{
	int mid=a_low+(key-a[a_low])/(a[a_high]-a[a_low])*(a_high-a_low);
	if(a[mid]==key)
		return mid;
	if(a[mid]>key)
		return insertion_search(a,key,a_low,mid-1);
	if(a[mid]<key)
		return insertion_search(a,key,mid+1,a_high);
	
	
}


/*
	选择排序函数：
	函数列表： 数组首地址*a, 要排序数组元素个数n
	使用方法：选中间元素做为参照，把比他小的元素放左边，大的放右边，再运用递归将左右子数组排序达到排序效果
*/
void chiose_sort(int *a,int n)
{
	int i,j,k,temp;
	for(i=0;i<n-1;i++)
	{
		k=i;				//保存i的值，用k进行循环排序
		for(j=i+1;j<n;j++)
			if(a[k]>a[j])	//如果第k=i个元素后面的元素小于i号元素，交换两个元素的标号，这样就将最小元素的标号放到最前面
				k=j;		//k指向最小元素，交换行号
		if(i!=k)		
		{					//i != k时交换，否则a[i]即为最小值
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
}

/*
	插入排序函数：
	函数列表： 数组首地址*a, 要排序数组元素个数n
	使用方法：首先把数组头两个元素排好序，再依次把后面的元素插入适当的位置。把数组元素插完也就完成了排序
*/
void insert_sort(int *a,int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0 && temp<a[j])
		{					//从a[i-1]开始找比a[i]小的数，同时把数组元素往后移
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;		//元素被插入
	}	
}