#include <cstdio>
#include <queue>

using namespace std;

int map[18][18] = {};
int N;
int count = 0;

queue< pair<int,pair<int,int> > > q;

void BFS(){
	int x = 1,y = 0,sig = 0;
	q.push(pair<int,pair<int,int>>(sig,pair<int,int>(x,y)));
	map[y][x] = 1;
	while(!q.empty())
	{
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		int cs = q.front().first;
		q.pop();
		if(cx == N-1 && cy== N-1){
			count++;
			continue;
		}
		//지금 상태에 따라 나누기
		switch(cs)
		{
			case 0:
				if(map[cy+1][cx+1] == 0 && map[cy][cx+1] == 0 &&map[cy+1][cx] == 0){
					printf("0 2\n");
					q.push(pair<int,pair<int,int>>(2,pair<int,int>(cx+1,cy+1)));
					q.push(pair<int,pair<int,int>>(0,pair<int,int>(cx+1,cy)));
				}
				else if(map[cy][cx+1] == 0){
					printf("0\n");
					q.push(pair<int,pair<int,int>>(0,pair<int,int>(cx+1,cy)));
				}
				break;
			case 1:
				if(map[cy+1][cx+1] == 0 && map[cy][cx+1] == 0 &&map[cy+1][cx] == 0){
					printf("1 2\n");
					q.push(pair<int,pair<int,int>>(2,pair<int,int>(cx+1,cy+1)));
					q.push(pair<int,pair<int,int>>(1,pair<int,int>(cx,cy+1)));
				}
				else if(map[cy+1][cx] == 0){
					printf("1\n");
					q.push(pair<int,pair<int,int>>(1,pair<int,int>(cx,cy+1)));
				}
				break;
			case 2:
				printf("2\n");
				if(map[cy+1][cx] == 0){
					if(map[cy+1][cx+1] == 0 && map[cy][cx+1] == 0){
						printf("0 1 2\n");
						q.push(pair<int,pair<int,int>>(2,pair<int,int>(cx+1,cy+1)));
						q.push(pair<int,pair<int,int>>(0,pair<int,int>(cx+1,cy)));
						q.push(pair<int,pair<int,int>>(1,pair<int,int>(cx,cy+1)));
					}
					else if(map[cy][cx+1] == 0){
						printf("0 1\n");
						q.push(pair<int,pair<int,int>>(0,pair<int,int>(cx+1,cy)));
						q.push(pair<int,pair<int,int>>(1,pair<int,int>(cx,cy+1)));
					}
					else{
						printf("1\n");
						q.push(pair<int,pair<int,int>>(1,pair<int,int>(cx,cy+1)));
					}
				}
				else if(map[cy][cx+1] == 0){
					printf("0\n");
					q.push(pair<int,pair<int,int>>(0,pair<int,int>(cx+1,cy)));
				}
				break;
		}//케이스별 분류가 종료
	}
}


int main(){
	scanf("%d",&N);
	for(int i = 0;i < N;++i){
		for(int j = 0;j < N;++j){
			scanf("%d",&map[i][j]);
		}
	}
	for (int i = 0;i < N;++i){
		map[i][N] = 1;
	}
	for (int i = 0;i <= N;++i){
		map[N][i] = 1;
	}
	BFS();
	printf("%d",count);
	return 0;
}

