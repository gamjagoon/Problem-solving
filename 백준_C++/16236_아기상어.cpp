#include <iostream>
#include <queue>
#include <vector>
#define mfor(i,s,e) for(auto i = s; i<= e;++i)
#define endl '\n'
using namespace std;
typedef struct point {
	int r,c;
}P;
bool operator<(P a, P b) {
	if(a.r == b.r)return a.c > b.c;
	else return a.r > b.r;
}
typedef struct baby {
	int size = 2;
	int val = 0;
	int time = 0;
	P pos;
	void sizeup() {
		if (val == size) {
			val = 0;
			size++;
		}
	};
}baby;
int arrsize,arr[21][21];
/*À§ ¿Þ ¿À ¾Æ*/
int dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
int gogi[7] ={0,0,0,0,0,0,0};
int gogicnt = 0;
bool inrange(P &a) {
	return a.r > 0 && a.c > 0 && a.r <= arrsize && a.c <= arrsize;
}
void view_debug() {
	mfor(i, 1, arrsize)
	{
		mfor(j, 1, arrsize)
		{
			if (arr[i][j] == 9) {
				cout<<"* ";
			}
			else {
				cout<<arr[i][j]<<' ';
			}
		}
		cout<<endl;
	}cout<<endl;
}
int doit(baby &shark) {
	queue<P>q;
	priority_queue<P>pq;
	bool ch[21][21]={false};
	q.push(shark.pos);
	ch[shark.pos.r][shark.pos.c] = true;
	int T = 1;
	while (!q.empty()) 
	{
		int qs = q.size();
		P ntmp;
		for (int i = 0; i < qs; ++i) 
		{
			P tmp = q.front();
			q.pop();
			for (int k = 0; k <= 3; ++k)
			{
				ntmp.r = tmp.r + dir[k][0];
				ntmp.c = tmp.c + dir[k][1];
				if (inrange(ntmp) && !ch[ntmp.r][ntmp.c])
				{
					if (arr[ntmp.r][ntmp.c] > shark.size){
						ch[ntmp.r][ntmp.c] = true;continue;
					}
					else if(arr[ntmp.r][ntmp.c]== shark.size || arr[ntmp.r][ntmp.c] == 0){
						ch[ntmp.r][ntmp.c] = true;
						q.push(ntmp);
					}
					else {
						ch[ntmp.r][ntmp.c] = true;
						pq.push(ntmp);
					}
				}
			}
		}
		if (!pq.empty()) {
			ntmp = pq.top();
			gogi[arr[ntmp.r][ntmp.c]]--;
			gogicnt--;
			arr[shark.pos.r][shark.pos.c] = 0;
			shark.pos = ntmp;
			arr[shark.pos.r][shark.pos.c] = 9;
			shark.val++;
			shark.time += T;
			shark.sizeup();
			while (!q.empty())q.pop();
			while (!pq.empty())pq.pop();
			return 1;
		}
		T++;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>arrsize;
	 baby shark;
	mfor(i, 1, arrsize) {
		mfor(j, 1, arrsize) {
			cin>>arr[i][j];
			if (arr[i][j] != 0) {
				if (arr[i][j] == 9) {
					shark.pos.r = i;
					shark.pos.c = j;
				}
				else {
					gogi[arr[i][j]]++;
					gogicnt++;
				}
			}
		}
	}
	while (doit(shark) != 0) {
		if(gogicnt == 0)break;
		bool flag = false;
		for (int i = shark.size; i >= 1; --i) {
			if (gogi[i] != 0) {
				flag = true;
			}
		}
		if(!flag)break;
	}
	cout<<shark.time;
	return 0;
}