 #include <iostream>
 #include <cstdio>
 #include <stack>
 #include <cmath>
 #include <cstring>
 using namespace std;
 int migong[12][12];
 const int tx[4]={0,1,0,-1};
 const int ty[4]={1,0,-1,0};
 int n, m, Sx, Sy, Fx, Fy;
 int minstep=100000, ways=0;
 
 void Dfs( int x, int y, int step)//函数返回值是路径数量
 {
 	if( x == Fx && y == Fy )
 		{ways++;
		 if(step<minstep)
 			minstep=step;
		 return;
		 }
	 //到达终点处理，也是函数的终止条件
	migong[x][y] = 1;
	 //表示我来过啦！
	for (int i=0;i<4;i++)
		if(!(migong[x+tx[i]][y+ty[i]])) 
			Dfs(x+tx[i],y+ty[i],step+1);
	 
	migong[x][y] = 0;
 }
 
 int main()
 {
 	cin >> n >> m >> Sx >> Sy >> Fx >> Fy;
	 //输入数据
	for (int i=0; i<=11; i++)
		for(int j=0; j<=11; j++)
			migong[i][j]=1;
	 //为迷宫砌墙
 	for (int i=1; i<=n; i++)
 		for(int j=1; j<=m; j++)
 			cin >> migong[i][j];
	Dfs(Sx, Sy, 1);
	if (!ways) minstep = 0;
	cout << ways << endl << minstep;
 	return 0;
 }
