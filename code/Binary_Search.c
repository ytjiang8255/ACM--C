# include <stdio.h> 
# include <string.h> 
# include <stdlib.h> 
#pragma warning(disable: 4996)	//添加的定义排除警告

#define Max 1000		//无需添加分号 ；

int binary_search();
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
/*		quick_sort(a, 0, n);			//问题出在数组的下标从 [0 ~~ n-1]
		for (i = 1; i<=n; i++)			//排序完后输出的元素须从i=1开始输出才能完整
			printf("%d  ", a[i]);
*/		
		
		printf("enter the numbers want to be find : ");
		scanf("%d", &q);
		sum = 0;
		printf("enter the key want to be find : ");
		for (i = 0; i<q; i++)
		{
			sum = 0;
			scanf("%d", &key);
			if (binary_search(a,n, key))	//返回值为1 则执行sum++
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
	二分搜素函数：		时间复杂度O(log n)
	函数列表： 数据存放的数组， 数组的长度， 搜索的关键字
	使用方法：	利用a[mid] == key 返回值为 1
*/
int binary_search(int *a,int n,int key)
{
	int left=0,right=n,mid;
	while (left<=right)
	{
		mid=(right+left)/2;		//这些值只是数组下标，没有对应的比较值
		if(key==a[mid]) 		//当key被找到 返回值 1
			return 1;
		if(key>a[mid])			//搜素后半部数据
			left=mid+1;			//将left值从原先的位置转移到中间位置，切记数组从0开始的！！！
		else if(key<a[mid])		//搜素前半部数据
			right=mid;
		
	}
	}
	return 0;	
}

	//运用递归的二分搜索
	int BinarySearch2(int a[], int value, int low, int high)
{
    int mid = low+(high-low)/2;
    if(a[mid]==value)
        return mid;
    if(a[mid]>value)
        return BinarySearch2(a, value, low, mid-1);
    if(a[mid]<value)
        return BinarySearch2(a, value, mid+1, high);
}



/*
	快速排序函数：
	函数列表： 数组首地址*a, 要排序数组起始元素下标low, 要排序数组结束元素下标high
	使用方法：选中间元素做为参照，把比他小的元素放左边，大的放右边，再运用递归将左右子数组排序达到排序效果
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


/*
	shell排序函数：
	函数列表： 数组首地址*a, 要排序数组元素个数n
	使用方法：首先把相距k(k>=1)的那几个元素排好序，再缩小k值（一般取其一半），再排序，直到k=1时完成排序。
*/
void shell_sort(int *a,int n)
{
	int i,j,k,temp;
	k=n/2;					//确定固定增量值
	while(k>=1)
	{
		for(i=k;i<n;i++)	//数组下标从k开始进行直插排序
		{
			temp=a[i];		//设置监视哨
			j=i-k;			//确定要进行比较的元素的最右边位置
			while(j>=0 && temp<a[j])
			{
				a[j+k]=a[j];//数据右移
				j-=k;		//向左移k个位置
			}
			a[j+d]=temp;	//在确定的位置插入s[j]  注意j是原来的j值
		}
		k/=2;				//增量变为原来的一半
	}	
}