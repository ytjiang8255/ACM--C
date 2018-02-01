#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct			//坐标点的结构体定义
{
	double x;
	double y;
}POINT;

POINT result[102];							//保存凸包上的点
POINT a[102];								
int n,top;

double Distance(POINT p1,POINT p2)			//两点间的距离
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double Multiply(POINT p1,POINT p2,POINT p3) //向量的叉积
{	
	//将p1作为参考的原点，然后利用矩阵的乘法计算向量的叉积
   return ((p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x)); 
}

int Compare(const void *p1,const void *p2)	//qsort（）函数的比较函数
{
	POINT *p3,*p4;
	double m;
    p3=(POINT *)p1; 
    p4=(POINT *)p2; 
	m=Multiply(a[0],*p3,*p4) ;
	if(m<0) return 1;
	else if(m==0&&(Distance(a[0],*p3)<Distance(a[0],*p4)))
		return 1;
	else return -1;		
	// -1/0 代表着计算是按照左手运算守则（面积为负数）还是按照右手运算法则（面积为正数）
	//相同的点计算出来的面积只会在右手还是左手运算里有正负差别！！！
}

void Tubao()		//保存凸包上的点的数据信息
{
   int i;
   result[0].x=a[0].x;
   result[0].y=a[0].y;
   result[1].x=a[1].x;
   result[1].y=a[1].y;
   result[2].x=a[2].x;
   result[2].y=a[2].y;
   top=2;
   for(i=3;i<=n;i++)
   {
       while(Multiply(result[top-1],result[top],a[i])<=0)
			top--;
       result[top+1].x=a[i].x;
       result[top+1].y=a[i].y;
       top++;
   }
}

int main()
{
   int i,p;
   double px,py,len,temp;
   while(scanf("%d",&n)!=EOF,n)
   {
       for(i=0;i<n;i++)
           scanf("%lf%lf",&a[i].x,&a[i].y);
       if(n==1)
       {
           printf("0.00\n");
           continue;
       }
       else if(n==2)
       {
           printf("%.2lf\n",Distance(a[0],a[1]));
           continue;
       }
       py=-1;
       for(i=0;i<n;i++)
	   {
           if(py==-1 || a[i].y<py)
           {
               px=a[i].x;
               py=a[i].y;
			   p=i;
           }
           else if(a[i].y==py && a[i].x<px)
           {
               px=a[i].x;
               py=a[i].y;
			   p=i;
           }
	   }
	   //swap(a[0],a[p])
	   temp=a[0].x;
	   a[0].x=a[p].x;
	   a[p].x=temp;
	   temp=a[0].y;
	   a[0].y=a[p].y;
	   a[p].y=temp;

       qsort(&a[1],n-1,sizeof(double)*2,Compare);
	   /*
		功 能： 使用快速排序例程进行排序
		头文件：stdlib.h
		用 法： void  qsort (void  *base,  int  num,  int  width,  int (*fcmp)(const void *,const void *));
		参数：
		1 待排序数组首地址
		2 数组中待排序元素数量
		3 各元素的占用空间大小
		4 指向比较函数的指针，用于确定排序的顺序

	   */
       a[n].x=a[0].x;
       a[n].y=a[0].y;
       Tubao();
       len=0.0;
       for(i=0;i<top;i++)
           len=len+Distance(result[i],result[i+1]);
       printf("%.2lf\n",len);
   }
   return 0;
}


