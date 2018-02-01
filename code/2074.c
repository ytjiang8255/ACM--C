#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/**
一个个大小差一圈的筐叠上去，使得从上往下看时，边筐花色交错.
输入是一个个的三元组，分别是，外筐尺寸n（n为满足0<n<80的奇整数），中心花色字符，外筐花色字符，后二者都为ASCII可见字符；
输出叠在一起的筐图案，中心花色与外筐花色字符从内层起交错相叠，多筐相叠时，最外筐的角总是被打磨掉。叠筐与叠筐之间应有一行间隔。

**/
int main()
{
	int n,i,j,flag=0,mark;
	char a,b,temp,map[100][100];
	while(scanf("%d%c%c",&n,&a,&b)!=EOF)
	{
		if(flag)
			printf("\n");
		flag=1;
		if((n-1)%4)
		{
			temp=a;
			a=b;
			b=temp;
		}
//		temp=a;
//		mark=1;
		for(i=0;i<=n/2;j++)
		{
			temp=a;
			mark=1;
			for(j=0;j<n;j++)
			{
				if(n!=1 && i==0 &&(j==0||j==n-1))
				{
					printf(" ");
					map[i][j]=' ';
					continue;
				}
				map[i][j]=t;
				printf("%c",temp);
				if(i>j || j>=(n-1-i))
				{
					if(mark)
					{
						temp=b;
						mark=0;	
					}
					else
					{
						temp=a;
						mark=1;
					}
				}
			}
			printf("\n");
		}
		
		for(i=n/2-1;i>=0;i--)		//对称地输出同行后面部分字符
		{
			for(j=0;j<n;j++)
				printf("%c",map[i][j]);
			printf("\n");
			
		}
		
	}	
	return 0;
}
					ERROR
----------------------------------------------------------------
{
	int i, d, k, a, j, flag=0;
    char b, c, m[100][100]={0},ch;
    while(scanf("%d %c %c",&a, &b, &c) != EOF)
	{
        if(flag == 1)
            printf("\n");
        
        flag = 1;
        if(a == 1)
		{
            printf("%c\n",b);
            continue;
        }
        
        d = a/2;		//中心位置；
        m[d][d] = b;	//中心位置放第一个字符，特殊排列单独在外部赋值 
        for(k = 1; k <= d; k++)
		{
            if(k%2 == 1)
                ch = c;		//k为偶数时打印第二个字符 
            else     
				ch = b;		//k为奇数时打印第一个字符
				
			/*
				注意i，j的初值，以及for()函数的判断条件
			*/	
            for(i = d-k, j = d-k; i <= d+k; i++)//i递增 j不变
                m[i][j] = ch;
            
            for(i = d+k, j = d-k; j <= d+k; j++)//i不变，j递增
                m[i][j] = ch;
    
            for(i = d+k, j = d+k; i >= d-k; i--)//i递减，j不变
                m[i][j] = ch;

            for(i = d-k, j = d+k; j >= d-k; j--)//i不变，j递减
                m[i][j] = ch;
            
        } 
		
		//将四个角上的元素赋值为空格
        m[0][0] = ' ';
        m[a-1][0] = ' ';
        m[a-1][a-1] = ' ';
        m[0][a-1] = ' ';
        for(i = 0; i < a; i++)
		{
            for(j = 0; j < a; j++)
			{
                printf("%c",m[i][j]);
            }
            printf("\n");
        }   
    }    
    return 0 ;
}