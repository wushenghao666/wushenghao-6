 #include <iostream>
 #include <cstdio>
 #include <stack>
 #include <cmath>
 #include <cstring>
 using namespace std;
 int migong[12][12];
 int counts = 0, min_counts=1000;
 
 int ways( int Sx, int Sy, int Fx, int Fy )
 {
 	counts ++;
 	if( Sx == Fx && Sy == Fy )
 		{if(counts<min_counts)
 			min_counts=counts;
		 return 1;
		 }
	migong[Sx][Sy] = 1;
	int num = 0;
	if(!migong[Sx][Sy-1])
		num += ways(Sx, Sy-1, Fx, Fy);
	if(!migong[Sx][Sy+1])
		num += ways(Sx, Sy+1, Fx, Fy);
	if(!migong[Sx+1][Sy])
		num += ways(Sx+1, Sy, Fx, Fy);
	if(!migong[Sx-1][Sy])
		num += ways(Sx-1, Sy, Fx, Fy);
	migong[Sx][Sy] = 0;
	counts --;
	return num;
 }
 
 int main()
 {
 	int n, m, Sx, Sy, Fx, Fy;
 	cin >> n >> m >> Sx >> Sy >> Fx >> Fy;
	for (int i=0; i<=11; i++)
		for(int j=0; j<=11; j++)
			migong[i][j]=1;
	 //周围我要砌一层墙 
 	for (int i=1; i<=n; i++)
 		for(int j=1; j<=m; j++)
 			cin >> migong[i][j];
	int way;
	way = ways(Sx, Sy, Fx, Fy);
	cout << way << endl << min_counts;
 	return 0;
 }