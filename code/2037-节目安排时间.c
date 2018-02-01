#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

输入数据包含多个测试实例，每个测试实例的第一行只有一个整数n(n<=100)，表示你喜欢看的节目的总数，
然后是n行数据，每行包括两个数据Ti_s,Ti_e (1<=i<=n)，分别表示第i个节目的开始和结束时间，
为了简化问题，每个时间都用一个正整数表示。

n=0表示输入结束，不做处理。

输出能完整看到的电视节目的个数，每个测试实例的输出占一行。
***************************************************
*/

int main()  
{
	int n,Ti_e[105]={0},Ti_s[105]={0};
	
	while(scanf("%d",&n) != EOF	&& n)
		{
			int t_s=0,t_e=0,sum=0,temp=0;
			for(int i=0;i<n;i++)
				scanf("%d%d",&Ti_s[i],&Ti_e[i]);
			
			for(int i=0;i<n;i++)
				for(int j=i;j<n;j++)
				{
					if(Ti_e[i]>Ti_e[j])
			{
				//swap(Ti_e[i],Ti_e[j]);
				temp = Ti_e[i];
				Ti_e[i] = Ti_e[j];
				Ti_e[j] = temp;
//				printf("%d   %d\n", Ti_s[i], Ti_e[i]);
				//swap(Ti_s[i],Ti_s[j]);
				temp = Ti_s[i];
				Ti_s[i] = Ti_s[j];
				Ti_s[j] = temp;
			}
				}
			sum++;
			t_s=Ti_s[0];
			t_e=Ti_e[0];
			for(int i=1;i<n;i++)
			{
				if(Ti_s[i]>=t_e)
				{
					sum++;
					t_e=Ti_e[i];
				}
				
			}	
			printf("%d\n",sum);		
		}	
	return 0;
}