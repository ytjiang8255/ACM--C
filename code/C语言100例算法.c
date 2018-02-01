#include<stdio.h>
/**************************************************
程序要求：正整数分解质因数

程序分析：对 n 进行分解质因数，应先找到一个最小的质数 k，然后按下述步骤完成：
(1)如果这个质数恰等于 n，则说明分解质因数的过程已经结束，打印出即可。
(2)如果 n != k，但 n 能被 k 整除，则应打印出 k 的值，并用 n 除以 k 的商,作为新的正整数你 n,重复执行第一步。
(3)如果 n 不能被 k 整除，则用 k+1 作为 k 的值,重复执行第一步。

**************************************************/

	int n,i;
	while(scanf("%d",&n)==1) 
	{
		printf("%d=",n);
		for(i=2;i<=n;i++)
		{
			while(n!=i)
			{
				if(n%i==0)
				{
					printf("%d*",i);
					n/=i;
				}
				else
				break;
			}
		}
		printf("%d\n",n);		//***注意这个n不是一开始的那个n，而是经过n=n/i运算的值
	}
========================================================


/**************************************************
程序要求：求最大公约数和最小公倍数

程序分析：利用辗转相除法

**************************************************/

int a,b,num1,num2,temp;
printf("please input two numbers:\n");
scanf("%d,%d",&num1,&num2);
if(num1<num2)
	{ 	
		temp=num1;
		num1=num2;
		num2=temp;
	}
a=num1;b=num2;		//利用中间变量a,b,防止原值因为运算而值改变
while(b!=0)			/*利用辗除法，直到 b 为 0 为止*/
{
	temp=a%b;
	a=b;
	b=temp;
}
printf("gongyueshu:%d\n",a);
printf("gongbeishu:%d\n",num1*num2/a);	//保存的原值在这重新被用起来了
}
========================================================
/**************************************************
程序要求：打印菱形图案

程序分析：先把图像分成两个部分来看待，前N行一个规律，后N - 1行一个规律
		  利用双重for循环，第一层控制行输出，第二行控制列输出。

**************************************************/

#define N 5			//打印的行数

int main()
{
	int i, j, k;
	for (i = 0; i <= N; i++)
	{
		for (j = 0; j <= N - i; j++)	//上半部分的菱形输出
			printf(" ");
		for (k = 0; k <= 2 * i; k++)	//上部分图像呈递增输出
			printf("*");
		printf("\n");
	}

	for (i = 0; i <= N-1; i++)
	{
		for (j = 0; j <= i+1; j++)		//下半部分的菱形输出
			printf(" ");
		for (k = 0; k <=2*(N-1) - 2 * i; k++)//下部分图像呈递减输出
			printf("*");
		printf("\n");
	}

	system("pause");
	return 0;
}
========================================================
/**************************************************
程序要求：字符串反转打印

程序分析：利用递归函数调用将输入的字符串以相反顺序打印出来

**************************************************/
int main()
{
	int N;
	scanf("%d%*c", &N);		//须屏蔽回车符的干扰
	void Change(int n);
	printf("\40:");			//\40作用是空一空格
	Change(N);
	printf("\n");

	system("pause");		//“pause”这个系统命令的功能很简单，就是在命令行上输出一行类似于“Press any key to exit”的字，
							//等待用户按一个键，然后返回。
	return 0;
}

void Change(int n)
{
	char next;
	if (n <= 1)
	{
		next = getchar();
		printf("\n\0");		//\0其实就是0，字符串存入字符数组的时候最后一个字符作为字符串的结尾。告诉计算机，这个字符串结束了。
		putchar(next);		//putchar 函数打印字符串自动换行
	}
	else
	{
		next = getchar();
		Change(n - 1);		//递归调用变换函数Change
		putchar(next);
	}
}
========================================================
/**************************************************
程序要求：字体色改变外加屏幕特定位置显示

程序分析：system("color number")  改变的是字体颜色
		  gotoxy(number ,number)  改变的是屏幕所在位置
		  system("cls")   清屏

**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
可以把控制台的标准输出窗口句柄得到GetStdHandle(STD_OUTPUT_HANDLE)（你可以理解为窗口的唯一标识）后
利用函数SetConsoleCursorPositon(HANDLE,COORD)。这里的HANDLE就是窗口句柄，GetStdHandle(STD_OUTPUT_HANDLE)作为第一个参数，
COORD是坐标对象，该对象成员只有两个X和Y,即坐标的具体位置。
*/
void gotoxy(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	int color;
	char a[16], n;
	while (scanf("%d",&n)==1)
	{
		system("cls");
		sprintf(a, "color %d", n);
		system(a);
		gotoxy(n, n);
		printf("Hello World!\n");
		sleep(1000);

	}
	
	return 0;
}





