#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
例如：某次考试一共8题（A，B，C，D，E，F，G，H），每个人做的题都在对应的题号下有个数量标记，
负数表示该学生在该题上有过的错误提交次数，但到现在还没有AC，正数表示AC所耗的时间，
如果正数a跟上一对括号，里面有个整数b，那就表示该学生提交该题AC了，耗去了时间a，同时，曾经错误提交了b次

输入数据的第一行是考试题数n（1≤n≤12）以及单位罚分数m（10≤m≤20），
每行数据描述一个学生的用户名（不多于10个字符的字串）以及对所有n道题的答题现状，
其描述采用问题描述中的数量标记的格式，见上面的表格，提交次数总是小于100，AC所耗时间总是小于1000。

将这些学生的考试现状，输出一个实时排名。实时排名显然先按AC题数的多少排，多的在前，
再按时间分的多少排，少的在前，如果凑巧前两者都相等，则按名字的字典序排，小的在前。
每个学生占一行，输出名字（10个字符宽），做出的题数（2个字符宽，右对齐）和时间分（4个字符宽，右对齐）。
名字、题数和时间分相互之间有一个空格。


**/
int main()
{
	
	return 0;
}
-----------------------------------------------

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct stu
{
    string name;
    int time;
    int solved;
}S[10001];
bool cmp(stu a,stu b)
{
    return a.solved != b.solved ? a.solved > b.solved:a.time < b.time;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int n, m, wa, time, d;
    string str;
    cin >> n >> m;
    d = 0;
    while (cin >> S[d].name)
    {
        S[d].time = 0;
        S[d].solved = 0;

        for (int j = 0; j < n;j++)
        {
            wa = 0;
            time = 0;
            cin >> str;
            if (str[0] == '0' || str[0] == '-')     // 如果没有AC，不处理
                continue;
            for (int k = 0; k < str.length();k++)
            {
                if(str[k] == '(')                   // 当遇到括号
                {
                    k++;
                    while (str[k] != ')')           // 记录括号中的WA次数
                    {
                        wa = wa * 10 + str[k] - '0';
                        k++;
                    }
                    break;
                }
                else                                // 还没有遇到括号
                {
                    time = time * 10 + str[k] - '0';// 记录本题的耗时
                }
            }
            S[d].solved++;
            S[d].time += (time + wa*m);
        }
        d++;
    }
    sort(S, S + d, cmp);
    for (int i = 0; i < d; i++) {
        printf("%-10s %2d %4d\n", S[i].name.c_str(), S[i].solved, S[i].time);
    }
    return 0;
}
======================================================================
#include<iostream>  
#include<cmath>  
#include<iomanip>  
#include<cstring>  
using namespace std;  
int n,m,person;  
struct stu  
{  
    char name[256][20];  
    int ac;  
    int time;  
};  
  
int change(char *score)  
{  
    int i,sum=0,erro1,erro2,errosum=0;  
    if(score[0]>'0'&&score[0]<='9')  
    {  
        for(i=0;;i++)           //数字个数  
        {  
            if(score[i]=='('||score[i]=='\0')  
            {  
                if(score[i]=='(')   　　　　　　　　　　　　//错误次数  
                {  
                    erro1=i+1;  
                    for(int j=i+1;;j++)  
                    if(score[j]==')')  
                    {  
                        erro2=j-1;            
                        break;  
                    }     
                    for(int j=erro2,jj=0;j>=erro1;j--,jj++)  
                        errosum+=(score[j]-48)*pow(10,jj);  
                }  
                break;  
            }  
        }  
        for(int j=i-1;j>=0;j--)          　　　　　　　　　　//用时  
        {  
            sum+=(score[j]-48)*pow(10,i-1-j);  
        }  
        return sum+errosum*m;  
    }  
    else  
        return 0;  
}  
  
void work(stu *p)  
{  
  
    for(int i=0;i<person;i++)  
    {  
        p[i].ac=0;  　　　　　　//ac 题数  
        p[i].time=0;    　　　　//总时间  
        for(int j=1;j<n+1;j++)  
        {  
            if(change(p[i].name[j])>0)  
            {  
                p[i].ac++;  
                p[i].time+=change(p[i].name[j]);  
            }                 
        }  
    }  
}  
  
void sort(stu *p)  
{  
    for(int i=0;i<person;i++)        //ａｃ次数排序  
    for(int j=0;j<person-1-i;j++)  
        if(p[j].ac<p[j+1].ac)  
            stu a=p[j];p[j]=p[j+1];p[j+1]=a;  
    for(int i=0;i<person;i++)        //时间排序  
    for(int j=0;j<person-1-i;j++)  
        if(p[j].time>p[j+1].time&&p[j].ac==p[j+1].ac)  
                stu a=p[j];p[j]=p[j+1];p[j+1]=a;  
    for(int i=0;i<person;i++)        //名字字典排序  
    for(int j=0;j<person-1-i;j++)  
        if(strcmp(p[j].name[0],p[j+1].name[0])>0&&p[j].time==p[j+1].time&&p[j].ac==p[j+1].ac)  
                stu a=p[j];p[j]=p[j+1];p[j+1]=a;  
}  
  
void input(stu *p)  
{  
    int i=0;  
    person=0;  
    while(cin>>p[i].name[0])  
    {  
        person++;  
        for(int j=1;j<n+1;j++)  
            cin>>p[i].name[j];  
        i++;  
    }  
}  
  
void output(stu *p)  
{  
    for(int i=0;i<person;i++,cout<<endl)  
    {  
        cout<<setw(10)<<left<<p[i].name[0]<<' '  
            <<setw(2)<<right<<p[i].ac<<' '  
            <<setw(4)<<right<<p[i].time;  
    }  
}  
  
int main()  
{  
    stu stuc[1000];  
    cin>>n>>m;  
        input(stuc);  
        work(stuc);  
        sort(stuc);  
        output(stuc);  
          
      
}  

