#include <stdio.h>


void reverse(char* s)
{
    // 获取字符串长度
    int len = 0;
    char* p = s;
	while (*p != 0)	
//	while (*p != '\0')	//也可以
    {
        len++;
        p++;
    }
    
    // 交换字符串 ...
    int i = 0;
    char c;
    while (i <= len / 2 - 1)
    {
        c = *(s + i);
        *(s + i) = *(s + len - 1 - i);
        *(s + len - 1 - i) = c;
        i++;
    }
}

int main()
{
   // char s[] = "www.runoob.com";
	char s[20] = {0};
	printf("enter string :\t");
	scanf("%s",&s);
	printf("string's lenth is :\t%d\n",strlen(s));
    printf("'%s' ==>\t", s);
    reverse(s);           // 反转字符串
    printf("'%s'\t\n", s);
    return 0;
}