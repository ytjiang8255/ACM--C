//	hdoj_1010月下版

# include <iostream.h> 
# include <string.h> 
# include <stdlib.h> 
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
输入由多个测试用例组成。 每个测试用例的第一行包含三个整数N，
M和T（1 <N，M <7; 0 <T <50），分别表示迷宫的大小和门打开的时间。
接下来的N行给出迷宫布局，每行包含M个字符。 字符是以下之一：
		'X'：一块墙，小狗不能进入;
		'S'：小狗的起点;
		'D'：门 要么
		'。'：一个空的块。

输入以三个0结束。 该测试用例不被处理。

如果小狗可以生存，打印一行“YES”，否则打印“NO”。
**/
char map[9][9]; 
int n,m,t,di,dj; 
bool escape; 
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}}; 
void dfs(int si,int sj,int cnt) 
{    int i,temp; 
   if(si>n||sj>m||si<=0||sj<=0) return; 
   if(cnt==t&&si==di&&sj==dj)    escape=1;
   if(escape) return; 
  
   temp=(t-cnt)-abs(si-di)-abs(sj-dj); 
   if(temp<0||temp&1) return; 
   for(i=0;i<4;i++){ 
      if(map[si+dir[i][0]][sj+dir[i][1]]!='X')
	  { 
         map[si+dir[i][0]][sj+dir[i][1]]='X'; 
         dfs(si+dir[i][0],sj+dir[i][1],cnt+1); 
         map[si+dir[i][0]][sj+dir[i][1]]='.'; 
      } 
   } 
   return ; 
} 



int main() 
{ 
	int i,j,si,sj; 
	while(cin>>n>>m>>t)
	{ 
	  if(n==0&&m==0&&t==0) break; 
	  int wall=0;
	  for(i=1;i<=n;i++) 
         for(j=1;j<=m;j++)
		 { 
            cin>>map[i][j]; 
            if(map[i][j]=='S') { si=i; sj=j; } 
            else if(map[i][j]=='D') { di=i; dj=j; } 
            else if(map[i][j]=='X') wall++; 
         } 
       if(n*m-wall<=t)
	   {
		   cout<<"NO"<<endl;
		   continue;
	   }
	   escape=0; 
       map[si][sj]='X';
       dfs(si,sj,0); 
       if(escape) cout<<"YES"<<endl; 
       else cout<<"NO"<<endl; 
   } 
   return 0; 
} 
