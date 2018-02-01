#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

#define QUIT 5
#define HOTEL1 180.00
#define HOTEL2 225.00
#define HOTEL3 255.00
#define HOTEL4 355.00
#define DISCOUNT 0.95
#define STARS "************************************"

int menu(void);
int getnights(void);
void showprice(double rate, int nights);
int main()
{
	int nights, code;
	double hotel_rate;

	while ((code = menu()) != QUIT)
	{
		switch (code)
		{
		case 1:	hotel_rate = HOTEL1;	break;
		case 2:	hotel_rate = HOTEL2;	break;
		case 3:	hotel_rate = HOTEL3;	break;
		case 4:	hotel_rate = HOTEL4;	break;
		default:	hotel_rate = 0;
			printf("error!\n");
			break;
		}
		nights = getnights();
		showprice(hotel_rate, nights);
	}
	printf("Thank you and goodbye!\n");		//当code等于5时不满足while循环则跳出大循环输出再见

	return 0;
}


/***************************
名称：		menu()菜单函数
参数：
作用：
***************************/
int menu(void)
{
	int code, status;
	printf("\n%s\n", STARS);
	printf("Enter the number of the order hotel:\n");
	printf("1) AAA\t2) BBB\t3) CCC\t4) DDD\n5) quit");
	printf("\n%s\n", STARS);

	while ((status = scanf("%d", &code)) != 1 || (code<1 || code >5))
	{
		if (status != 1)
			scanf("%*s");
		printf("please enter an inter form 1 to 5.\n");
	}

	return code;
}


/***************************
名称：		menu()菜单函数
参数：
作用：
***************************/
int getnights(void)
{
	int nights=0;
	printf("How many nights are needs?\t");
	while (scanf("%d", &nights) != 1)
	{
		scanf("%*s");
		printf("Please enter an integer!!!\n");
	}

	return nights;
}


/***************************
名称：		menu()菜单函数
参数：
作用：
***************************/
void showprice(double rate, int nights)
{
	int n;
	double total = 0, factor = 1;

	for (n = 1; n <= nights; n++, factor *= DISCOUNT)
		total += rate*factor;
	printf("The total cost will be %.2lf Yuan.\n\n\n", total);

}