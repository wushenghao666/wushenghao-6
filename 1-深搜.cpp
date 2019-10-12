 #include <iostream>
 #include <cstdio>
 #include <stack>
 #include <cmath>
 #include <cstring>
 using namespace std;
 int migong[12][12];
 int counts = 0, min_counts=100000;//counts为路径长度
 
 int ways( int Sx, int Sy, int Fx, int Fy )//函数返回值是路径数量
 {
 	if( Sx == Fx && Sy == Fy )
 		{if(counts<min_counts)
 			min_counts=counts;
		 return 1;
		 }
	 //到达终点处理，也是函数的终止条件
	migong[Sx][Sy] = 1;
	 //表示我来过啦！
	int num = 0;
	 //用以记录路径总数的变量
	if(!migong[Sx][Sy-1]){
		counts ++;
		num += ways(Sx, Sy-1, Fx, Fy);
		counts --;}
	if(!migong[Sx][Sy+1]){
		counts ++;
		num += ways(Sx, Sy+1, Fx, Fy);
		counts --;}
	if(!migong[Sx+1][Sy]){
		counts ++;
		num += ways(Sx+1, Sy, Fx, Fy);
		counts --;}
	if(!migong[Sx-1][Sy]){
		counts ++;
		num += ways(Sx-1, Sy, Fx, Fy);
		counts --;}
	 
	migong[Sx][Sy] = 0;
	return num;
 }
 
 int main()
 {
 	int n, m, Sx, Sy, Fx, Fy;
 	cin >> n >> m >> Sx >> Sy >> Fx >> Fy;
	 //输入数据
	for (int i=0; i<=11; i++)
		for(int j=0; j<=11; j++)
			migong[i][j]=1;
	 //为迷宫砌墙
 	for (int i=1; i<=n; i++)
 		for(int j=1; j<=m; j++)
 			cin >> migong[i][j];
	int way;
	way = ways(Sx, Sy, Fx, Fy);
	cout << way << endl ;
	if(way) cout << min_counts;
	else cout << 0;
	 //异常处理
 	return 0;
 }
