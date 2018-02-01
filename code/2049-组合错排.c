#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

输入数据的第一行是一个整数C,表示测试实例的个数，
然后是C行数据，每行包含两个整数N和M(1<M<=N<=20)。
请输出一共有多少种发生这种情况的可能，每个实例的输出占一行。
组合 + 错排
错排公式 的 d [ i ] = (i - 1) * ( d[i - 1] + d[ i - 2] );
Cnm=m!/((m-n)!n!)		[m中错排n个元素]

 *************************************************** 
double cal(int n, int m) 
{  
    double i, t1=1, t2=1, t3=1;  
      
    for(i=1; i<=n; i++)  
        t1 *= i;  
    for(i=1; i<=m; i++)  
        t2 *= i;  
    for(i=1; i<=n-m; i++)  
        t3 *= i;  
    return t1 / t2 / t3;  
      
}  
  
int main() {  
      
    int n, i, a, b;  
    __int64 d[21] = {0, 0, 1, 2}, e;  
      
    for(i=4; i<21; i++)  
        d[i] = (i-1) * (d[i-1] + d[i-2]);  
      
    while(~scanf("%d", &n)) {  
          
        for(i=0; i<n; i++) {  
            scanf("%d%d", &a, &b);  
            e = cal(a, b);  
            printf("%I64d\n", e * d[b]);  
        }  
          
    }  
      
    return 0;  
}  

*/
long long int f(int  x)
{
	long long ft = 1;
	int i;
	for (i = 1; i <= x; i++)
		ft *= i;
	return (ft);
}

int main()
{
	int  n, m;
	int c;
	while (scanf("%d", &c) != EOF)
	{
		long long a[22];
		a[1] = 0;
		a[2] = 1;
		for (int i = 3; i <= 20; i++)
			a[i] = (a[i - 2] + a[i - 1])*(i - 1);

		for (int i = 0; i < c; i++)
		{
			long long f1, f2;
			scanf("%d%d", &n, &m);
			f1 = f(n);
			f2 = f(m);
			printf("%lld\n", f1 / (f(n - m)*f2)*a[m]);
		}
	}
	return 0;

}