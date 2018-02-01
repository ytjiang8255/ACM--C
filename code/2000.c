#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
	*************************************************************
	输入三个字符后，按各字符的ASCII码从小到大的顺序输出这三个字符。
	************************************************************

*/
int main(void)
{
	char C1, C2, C3, t;
	while (scanf("%c%c%c%*c", &C1, &C2, &C3) != EOF)
	/*	用"%*c"(空字符，不存储字符的字符)滤掉回车
		其中%c是读一个字符，而中间的*号是跳过一个字符。
		意思就是读取一个字符但并不赋值给变量
		*: 星号-----------空读一个数据
		回车符 / CR (carriage return)  对应ASCII编码如下： 
			Bin （2进制）：0000 1101 
			Dec（10进制）：13        
			Hex（16进制）：0D
	    while((a=getchar())!=EOF)
	   {
	     b=getchar();
	     c=getchar();
         getchar();    //在录入c后用getchar()滤掉回车
		}
	*/
	
	
	{
		if (C1 > C2)
		{
			t = C1;
			C1 = C2;
			C2 = t;
		}
		if (C1 > C3)
		{
			t = C1;
			C1 = C3;
			C3 = t;
		}
		if (C2 > C3)
		{
			t = C2;
			C2 = C3;
			C3 = t;
		}
		printf("%c %c %c\n", C1, C2, C3);
	}

	return 0;
	
}