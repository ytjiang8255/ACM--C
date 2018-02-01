#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
输入  由几个数据集组成。 每个集合以包含Bob已构建的堆栈数量n的行开头。 输出线之间的空白!!!!
下一行包含n个数字，n个堆栈的高度。 您可以假设1≤n≤50且1≤hi≤100。
砖的总数将被堆叠的数量除尽。 因此，总是可以重新排列砖，使得所有的堆叠具有相同的高度。
输入以n = 0开头的集合终止。不应该对该集合进行处理。
输出  打印必须移动的砖块的最小数量，以使所有的堆叠都具有相同的高度。
6
5 2 4 1 7 5
0
--------------
5
**/
int main()
{
	int N,a[51],i,sum,aver=0,count=0,flag=0;
	while(scanf("%d",&N)==1 && N)
	{
		sum=0;
		if(flag)		//输出线之间的空白!!!
        printf("\n");
        flag=1;
		for(i=0;i<N;i++)
		{
			scanf("%d",&a[i]);
			sum +=a[i];
		}	
		aver=sum/N;
		for(i=0;i<N;i++)
		{
			count+=abs(a[i]-aver);
				
		}
		printf("%d\n",count);
	}
	return 0;
}