#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
输入首先是一个正整数M，表示M个测试实例。每个实例的输入有2行，
首先是一个正整数N（N <= 500)，表示有N个朋友，下一行是N个正整数，表示具体的坐标(所有数据均<=10000).
输出访问完所有朋友所花的最少时间，每个实例的输出占一行。
**/
void chiose_sort(int *a,int n);
int main()
{
	int M,N,a[502],i,j,sum[502],Min;
	while(scanf("%d",&M)==1)
		while(M--)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
			scanf("%d",&a[i]);
		
		chiose_sort(a,N);		//选择排序法
		
	//		从n / 2处开始距离最短
	// 		for(i=0;i<N;i++)
	//			sum+=abs(a[i]-a[N/2]);
		
		for(i=0;i<N;i++)
			sum[i]=0;
		for(i=0;i<N;i++)
			sum[0]+=abs(a[0]-a[i]);
		Min=sum[0];				//最小路程比较
		
		for(i=1;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				sum[i]+=abs(a[i]-a[j]);//路程累加计算
			}
			if(Min>sum[i])
				Min=sum[i];		//比较输出最小路程
		}
		printf("%d\n", Min);		
	}
	return 0;
}


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