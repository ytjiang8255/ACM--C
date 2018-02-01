#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
有多组数据，每组一行，每组就是一篇小文章。每篇小文章都是由小写字母和空格组成，没有标点符号，遇到#时表示输入结束。
每组只输出一个整数，其单独成行，该整数代表一篇文章里不同单词的总数。
sscanf(a,"%s",ch)中a为将要读字符串中所要读入单词的首地址，字符读取到空格或者‘\0’结束并存入字符数组ch中，所以每次读取单词时h 需要多加 1，为了不把空格读进ch中。
**/

#define Max 1000
int main()
{
	char word[Max],ch[10],b[Max][10];
	int count,i,lenth,j;
	while(gets(word)!=NULL)
	{
		if( strcmp(word,"#")==0)
			break;
		
		j=0;
		count =0;
		lenth=strlen(word);
		while(j<lenth)
		{
			sscanf(word+j,"%s",ch);
			count +=strlen(ch)+1;
			for(i=0;i<count;i++)
				if(!strcmp(b[i],ch))
					break;
			if((i==count))
				strcpy(b[count++],ch);
		}
		printf("%d\n",count);
	}
	return 0;
}
