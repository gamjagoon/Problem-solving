#include <iostream>
using namespace std;

int N;
int visited[18][18];

void fill_check(int r,int c) {
	int nr = r,nc_r = c,nc_l = c;
	while(nr < N-1){
		nr++;
		nc_r++;
		nc_l--;
		visited[nr][c]++;
		if(nc_r < N) visited[nr][nc_r]++;
		if(nc_l >= 0)visited[nr][nc_l]++;
	}
}

void del_check(int r,int c) {
	int nr = r,nc_r = c,nc_l = c;
	while(nr < N-1){
		nr++;
		nc_r++;
		nc_l--;
		visited[nr][c]--;
		if(nc_r < N) visited[nr][nc_r]--;
		if(nc_l >= 0)visited[nr][nc_l]--;
	}
}

//for debug
void view_map(){
	for(int i = 0 ; i < N; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(visited[i][j]){
				cout<<"1 ";
			}
			else cout<<"0 ";
		}cout<<endl;
	}
	cout<<endl;
}

int back(int r){
	if(r == N){
		return 1;
	}
	else 
	{
		int sum = 0;
		for(int i = 0; i < N;++i){
			if(!visited[r][i])
			{
				visited[r][i]++;
				fill_check(r,i);
				sum += back(r+1);
				visited[r][i]--;
				del_check(r,i);
			}
		}
		return sum;
	}
}


int main()
{
	cin>>N;
	cout<<back(0);
}