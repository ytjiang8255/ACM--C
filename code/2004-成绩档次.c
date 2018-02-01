#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
	*************************************************************
				输入分数后，按各分数区分成绩档次。
	************************************************************

*/
int main(void)
{
	int score,n;
	while (scanf("%d",&score) != EOF)
	{
		if(score>=0 && score<=59)
			n =1;
		else if (score >=60 && score<=69)
			n =2;
		else if (score>= 70 && score <=79)
			n =3;
		else if (score>= 80 && score <=89)
			n =4;
		else if (score>= 90 && score <=100)
			n= 5;
		else n =6;
		
		switch(n)
		{
			case 1: printf("E");break;
			case 2: printf("D");break;
			case 3: printf("C");break;
			case 4: printf("B");break;
			case 5: printf("A");break;
			case 6: printf("Score is error~");break;
			
		}
		
	}
	return 0;
}