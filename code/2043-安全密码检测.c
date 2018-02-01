#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

一般来说一个比较安全的密码至少应该满足下面两个条件：

(1).密码长度大于等于8，且不要超过16。
(2).密码中的字符应该来自下面“字符类别”中四组中的至少三组。

这四个字符类别分别为：
1.大写字母：A,B,C...Z;
2.小写字母：a,b,c...z;
3.数字：0,1,2...9;
4.特殊符号：~,!,@,#,$,%,^;

给你一个密码，你的任务就是判断它是不是一个安全的密码。

输入数据第一行包含一个数M，接下有M行，
每行一个密码（长度最大可能为50），密码仅包括上面的四类字符。
判断这个密码是不是一个安全的密码，是的话输出YES，否则输出NO。

***************************************************
*/
int main()
{
	int N;
	char password[52] = { 0 };
	while (scanf("%d", &N) != EOF)
	{
		while (N--)
		{
			scanf("%s", password);
			int len = strlen(password);
			if (len >= 8 && len <= 16)
			{
				int p1 =0, p2 =0, p3 =0, p4 = 0;
				int sum = 0;
				for (int i = 0; i<len; i++)
				{
					if (password[i]>='A' && password[i]<= 'Z')		//注意值的比较包括大于等于或者小于等于
						p1 = 1;
					if (password[i]>='a' && password[i]<= 'z')
						p2 = 1;
					if (password[i]>='0' && password[i]<= '9')
						p3 = 1;
					if (password[i] == '~' || password[i] == '!' || password[i] == '@'
						|| password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^')
						p4 = 1;
				}
				if ((p1 + p2 + p3 + p4) >=3)	printf("YES\n");
				else		 printf("NO\n");
			}
			else
				printf("NO\n");
		}
	}	
	return 0;
}