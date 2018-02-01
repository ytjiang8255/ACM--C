#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
方程：Ai = (Ai-1 + Ai+1)/2 - Ci (i = 1, 2, 3, .... n).
若给出A0, An+1, 和 C1, C2, .....Cn.
首先是一个正整数n,(n <= 3000); 然后是2个数a0, an+1.接下来的n行每行有一个数ci(i = 1, ....n);输入以文件结束符结束。
输出所求得的a1(保留2位小数).
1
50.00
25.00
10.00
2
50.00
25.00
10.00
20.00
----------
27.50
15.00
通式：对于An+1。  A1 = n /（n + 1） * A0 + 1 /（n + 1）* An+1 
						- 2*n /（n + 1）* C1 - 2*（n - 1）/（n + 1）* C2 - .....2 /（n + 1）* Cn-1
**/
int main()
{
	float A0,An,c[3001],ans,k;
	int i,n;
	while (scanf("%d", &n) == 1 && n)
	{
		ans = 0;
		scanf("%f%f", &A0, &An);
		for (i = 1; i <= n; i++)
			scanf("%f", &c[i]);
		k = 2;
		for (i = n; i > 0; i--)
		{
			c[i] *= k;
			k += 2;
			ans += c[i];
		}
		//a[1]=1/(n+1)*(a[n+1]+n*a[0]-2*c[n]-4*c[n-1]-8*c[n-2]...-pow(2,n)*c[1]);
		float sum = (float)1 / (n + 1)*(An + A0*n - ans);
		printf("%.2f\n", sum);
	}
	
（2）-------------------------------------------------------	
	while (scanf("%d", &n) == 1 && n)
	{
	
		sum = 0, total = 0;
		j = n;						//利用j作为中间变量
		scanf("%f%f", &A0, &An);
		ans = j*A0 + An;
		for (i = 1; i <= n; i++)
		{
			scanf("%f", &k);
			sum += j*k;
			j--;			//如果直接用n，这个n值不再是前面的n，则后面语句的计算就是错误的
		}
		//		A1 = [nA0 + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn)]/(n+1);
		total = (ans - 2 * sum) / (n + 1);
		
		printf("%.2f\n", total);
	}
------------------------------------------------------------	
/*	error code！！！

	while(scanf("%d",&n)==1 && n)
	{
		ans=0;
		scanf("%f%f",&A0,&An);
		for(i=1;i<=n;i++)
			scanf("%f",&c[i]);
		ans=(float)n/(float)(n+1)*A0+(float)1/(float)(n+1)*An;	//必须将n强制转换成float类型
		k=n*2;
		for(i=1;i<=n;i++)
		{
			ans -=(float)k/(float)(n+1)*c[i];
			k-=2;
		}
		printf("%.2f\n",ans);
	}
*/
	return 0;
}