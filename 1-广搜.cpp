#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <queue>
using namespace std;

int migong[12][12];
const int tx[4]={0,1,0,-1};
const int ty[4]={1,0,-1,0};
int n, m, Sx, Sy, Fx, Fy;
int minstep=100000;
struct point{
	int x, y, step;
};

void Bfs(int x, int y)
 {
 	queue<point> myque;
 	point tp;
 	tp.x = x;tp.y = y;tp.step = 1;
 	myque.push(tp);
 	migong[tp.x][tp.y] = 1;
 	//把初始节点放入队列中 
 	while(!myque.empty())//如果队列为空且未return，问题无解，失败退出 
 	{
	 	tp = myque.front();myque.pop();
	 	//取出第一个节点 
	 	if (tp.x==Fx&&tp.y==Fy)
			{minstep=tp.step;return;}
		//若为目标节点，成功退出
		for (int i=0;i<4;i++)
		if(!(migong[tp.x+tx[i]][tp.y+ty[i]])) 
		{
			point tmp;
			tmp.x = tp.x + tx[i];
			tmp.y = tp.y + ty[i];
			tmp.step = tp.step + 1;
			migong[tmp.x][tmp.y] = 1;
			myque.push(tmp);
		}
		//若不为目标节点，扩展它 
	 }	
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
	Bfs(Sx, Sy);
	if(minstep==100000) minstep=0;
	cout << "最短步数：" << minstep;
 	return 0;
 }
