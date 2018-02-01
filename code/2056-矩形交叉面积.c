#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************
给定两个矩形和每个矩形对角线上两个点的坐标，
计算两个矩形的相交部分的面积。 其侧面与OX和OY平行
输入第一行输入是8个正数，表示必须在每个对角线上的四个点的坐标。
8个数字是x1，y1，x2，y2，x3，y3，x4，y4。
这意味着两点 第一个矩形是（x1，y1），（x2，y2）;
第二个矩形的另外两个点是（x3，y3），（x4，y4）。
将相交部分的区域输出在一行中。最多可以存放2位小数。

基本步骤：
1.处理同一矩形中的左下点和右上点的坐标。
两个横坐标 相比 和 两个纵坐标 相比 ， 从中进行交换。
2.找出的 长和宽 。
a.如果两个矩形是相离的话（x1>x4||x2y1>y4||y2）,那么直接输出 0.00
b.如果两个矩形是相交或包含，从中去找出重叠矩形的左下点和右上点的坐标
（1）a = x1
（2）b = x2
（3）c = y1
（4）d = y2
左下点 （a,c） 右上点 (b,d)
3.求重叠矩形的面积
S=(b-a)*(d-b)

***************************************************
*/
float max(float a,float b)
{
 if(a>b)
  return a;
 else
  return b;
}

float min(float a,float b)
{
 if(a<b)
  return a;
 else
  return b;
}


int main()
{
	float x1，y1，x2，y2,x3，y3，x4，y4,temp;
	while(scanf("%f%f%f%f%f%f%f%f",&x1，&y1，&x2，&y2,&x3，&y3，&x4，&y4));
	{
		if(x1>x2)
			{temp=x1; x1=x2; x2=temp;}
		if(y1>y2)
			{temp=y1; y1=y2; y2=temp;}
		if(x3>x4)
			{temp=x3; x3=x4; x4=temp;}
		if(y3>y4)
			{temp=y3; y3=y4; y4=temp;}	
		
		x1=max(x1,x3);
		y1=min(y1,y3);
		x2=max(x2,x4);
		y2=min(y2,y4);
	
		if(x1>x2 || y1>y2)
			printf("0\n");
		else
			printf("%.2f",(x2-x1)*(y2-y1));
		
	}
	
	return 0;
}

============================================
while (scanf("%f%f%f%f%f%f%f%f", &x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF)
	{
		if (x1>x2)
		{
			temp = x1; x1 = x2; x2 = temp;
			temp = y1; y1 = y2; y2 = temp;
		}
		if (y1>y2)
		{
			temp = y1; y1 = y2; y2 = temp;
		}
		if (x3>x4)
		{
			temp = x3; x3 = x4; x4 = temp;
			temp = y3; y3 = y4; y4 = temp;
		}
		if (y3>y4)
		{
			temp = y3; y3 = y4; y4 = temp;
		}

		x1 = max(x1, x3);
		y1 = max(y1, y3);
		x2 = min(x2, x4);
		y2 = min(y2, y4);
		if (x4 > x1 && y4 > y1 && x3 < x2 && y3 < y2)
			printf("%.2f\n", (x2 - x1)*(y2 - y1));
		else
			printf("0.00\n");
	}