#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <queue>
using namespace std;

int qipan[360];
int card[5]={0};
int n, m, tmp;
int F[45][45][45][45];

int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> qipan[i];
	while(m--){
		cin >> tmp;
		card[tmp]++;
	}
	F[0][0][0][0]=qipan[0];
	 for(int a=0;a<=card[1];a++)
        for(int b=0;b<=card[2];b++)
            for(int c=0;c<=card[3];c++)
                for(int d=0;d<=card[4];d++)
                {
                    int position=a+b*2+c*3+d*4;
                    if(a!=0)    F[a][b][c][d]=max(F[a][b][c][d],F[a-1][b][c][d]+qipan[position]);
                    if(b!=0)    F[a][b][c][d]=max(F[a][b][c][d],F[a][b-1][c][d]+qipan[position]);
                    if(c!=0)    F[a][b][c][d]=max(F[a][b][c][d],F[a][b][c-1][d]+qipan[position]);
                    if(d!=0)    F[a][b][c][d]=max(F[a][b][c][d],F[a][b][c][d-1]+qipan[position]);
                }   
	cout <<F[card[1]][card[2]][card[3]][card[4]];		
}
