#include <iostream>
#include <vector>
#include <array>
#define INF 1000000009
#define endl '\n'

using namespace std;

array<array<int,19>, 19>arr;

pair<int,int> solve(int r,int c){
	int com = arr[r][c];
	int cnt = 1;int tmp = 1;
	while(c + tmp < 19 && arr[r][c + tmp] == com)tmp++;
	cnt += tmp - 1;tmp = 1;
	if(cnt < 6){
		while(c - tmp >= 0 && arr[r][c - tmp] == com)tmp++;
		--tmp;cnt += tmp;
		if(cnt == 5)return make_pair(r,c - tmp);
	}
	cnt = tmp = 1;
	while(r + tmp < 19 && arr[r + tmp][c] == com)tmp++;
	cnt += tmp - 1;tmp = 1;
	if(cnt < 6){
		while(r- tmp >= 0 && arr[r - tmp][c] == com)tmp++;
		--tmp;cnt += tmp;
		if(cnt == 5)return make_pair(r - tmp,c);
	}
	cnt = tmp = 1;
	while(r + tmp < 19 && c + tmp < 19 && arr[r + tmp][c+tmp] == com)tmp++;
	cnt += tmp - 1;tmp = 1;
	if(cnt < 6){
		while(r- tmp >= 0 && c- tmp >= 0&& arr[r - tmp][c - tmp] == com)tmp++;
		--tmp;cnt += tmp;
		if(cnt == 5)return make_pair(r + tmp,c + tmp);
	}
	cnt = tmp = 1;
	while(r - tmp >= 0 && c + tmp < 19&& arr[r - tmp][c + tmp] == com)tmp++;
	cnt += tmp - 1;tmp = 1;
	if(cnt < 6){
		while(r + tmp < 19 && c - tmp >= 0 && arr[r + tmp][c - tmp] == com)tmp++;
		--tmp;cnt += tmp ;
		if(cnt == 5)return make_pair(r + tmp,c - tmp);
	}
	return make_pair(-1,-1);
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	for(int r = 0; r < 19; r++){
		for(int c = 0 ; c < 19; c++){
			cin>>arr[r][c];
		}
	}
	for(int r = 0; r< 19;++r){
		for(int c = 0; c < 19; ++c){
			if(arr[r][c] == 0)continue;
			auto[R,C] = solve(r,c);
			if(R >= 0){
				cout<<arr[r][c]<<'\n';
				cout<<R + 1<<' '<<C + 1;
				return 0;
			}
		}
	}
	cout<<0;
}
