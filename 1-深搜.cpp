 #include <iostream>
 #include <cstdio>
 #include <stack>
 #include <cmath>
 #include <cstring>
 using namespace std;
 int migong[12][12];
 int counts = 0, min_counts=1000;
 
 int ways( int Sx, int Sy, int Fx, int Fy )//该函数返回值是路径数
 {
 	counts ++;
	 //每执行一次函数，距离+1
 	if( Sx == Fx && Sy == Fy )
 		{if(counts<min_counts)
 			min_counts=counts;
		 return 1;
		 }
	 //到达终点
	migong[Sx][Sy] = 1;
	 //表示我来过啦！
	int num = 0;
	if(!migong[Sx][Sy-1])
		num += ways(Sx, Sy-1, Fx, Fy);
	if(!migong[Sx][Sy+1])
		num += ways(Sx, Sy+1, Fx, Fy);
	if(!migong[Sx+1][Sy])
		num += ways(Sx+1, Sy, Fx, Fy);
	if(!migong[Sx-1][Sy])
		num += ways(Sx-1, Sy, Fx, Fy);
	 //四面来一次函数
	migong[Sx][Sy] = 0;
	counts --;
	 //这两步是回退
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
	cout << way << endl << min_counts;
 	return 0;
 }
