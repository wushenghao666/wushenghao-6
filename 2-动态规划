#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <queue>
using namespace std;

int qipan[360];
int card[5]={0};
int max_carrot=0;
int n, m, tmp;

void qianjin(int sum,int position){
	sum+=qipan[position];
	if(position==n-1) {
		if(sum>max_carrot) max_carrot=sum;
		return;
	}
	for(int i=1;i<=4;i++)
		if(card[i]) {card[i]--;qianjin(sum,position+i);card[i]++;}
}

int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> qipan[i];
	while(m--){
		cin >> tmp;
		card[tmp]++;
	}
	qianjin(0,0);
	cout << max_carrot;
	 
}
