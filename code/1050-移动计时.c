/*
输入由T个测试用例组成。 测试用例的数量（T在输入的第一行给出）每个测试用例以包含整数N，1 <= N <= 200的行开始，
表示要移动的表的数量 以下N行包含两个正整数s和t，表示表格要从房间号s移动到房间号码t（N行中每个房间号码最多出现一次），
从第N + 3行开始， 剩余测试用例与上述相同。

输出应包含完成移动的最短时间（以10分钟为单位），每行一个。
*/



#include <iostream>    
using namespace std;    
int main()    
{ int t,i,j,N,P[200];   
   int s,d,temp,k,min;    
   cin>>t;    
   for(i=0;i<t;i++)    
      {    
         for(j=0;j<200;j++)    
              P[j]=0;    
         cin>>N;    
        for(j=0;j<N;j++)    
            {    
               cin>>s>>d;    
               s=(s-1)/2;    
               d=(d-1)/2;   
               if(s>d)    
               {   
                   temp=s;    
                     s=d;    
                     d=temp;    
               }    
				   for (k = s; k <= d; k++)
				{
					P[k]++;			//移动时通过的房间加一
	//				cout << P[k] << endl;
				}
			}
		min = -1;
		for (j = 0; j<200; j++)
		if (P[j]>min)			//min的值不断修改，直至计算出移动通过的最大数，既用时等候次数
		{
			min = P[j];
//			cout << P[j] << endl;
		}   

		
         cout<<min*10<<endl;    
      }    
   return 0;    
}    
    
	
	
//============================================================================
	
	
	
#include<iostream>
using namespace std;
int main()
{
    int t, m, res = 0, a, b, i, j, k, time = 0, n[201];
    cin >> t;
    for (k = 1; k <= t; k++)
    {
        for (i = 0; i <= 200; i++)
        {
            n[i] = 0;
        }
        time = 10;
        cin >> m;
        for (i = 1; i <= m; i++)
        {
            cin >> a >> b;
            // 这里b可以大于a的，所以要交换a b
            if (a > b) {
                j = a;
                a = b;
                b = j;
            }
            for (j = (a + 1) / 2; j <= (b + 1) / 2; j++)
            {
                n[j]++;
            }
        }
        for (i = m; i >= 1; i--)
        {
            for (j = 1; j <= 200; j++)
            {
                if (n[j] == i)
                {
                    time = i*time;
                    res = 1;
                    break;
                }
            }
            if (res == 1)
                break;
        }
        cout << time << endl;
        res = 0;
    }
    return 0;
}