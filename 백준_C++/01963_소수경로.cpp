#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <array>
#define INF 1000000009
#define endl '\n'

using namespace std;

//Global

constexpr int Max = 10001;
char is_prime[Max];
array<bool,Max>visit;

void make_prime(){
	for(int i = 4; i < Max;i += 2){
		is_prime[i] = true;
	}
	for(int i = 6; i < Max;i += 3){
		is_prime[i]= true;
	}
	for(int i = 5; i < Max;i++){
		if(is_prime[i])continue;
		for(int j = i*2;j < Max;j+=i){
			is_prime[j] = true;
		}
	}
}

vector<int> next_int(int A,int at){
	int ori = A;
	int arr[4];
	for(int i = 0 ; i < 4; i++){
		arr[i] = ori%10;ori/=10;
	}
	vector<int>ret;
	int com = arr[at];
	if(at ==3){
		for(int i = 1; i <= 9; i++){
			if(i == com)continue;
			arr[at] = i;
			int tmp = 0;
			for(int j = 3; j >= 0 ; j--){
				tmp+=arr[j];
				tmp*=10;
			}tmp/=10;
			if(!is_prime[tmp]){
				ret.push_back(tmp);
			}
		}
	}else{
		for(int i = 0;i <= 9; i++){
			if(i == com)continue;
			arr[at] = i;
			int tmp = 0;
			for(int j = 3; j >= 0 ; j--){
				tmp+=arr[j];
				tmp*=10;
			}tmp/=10;
			if(!is_prime[tmp]){
				ret.push_back(tmp);
			}
		}
	}
	return ret;
}

int bfs(int A,int B){
	int cnt = 0;
	queue<int>q;
	q.push(A);
	visit.fill(false);
	while(!q.empty()){
		int sz = q.size();
		for(int i = 0 ; i < sz;i++){
			int curr = q.front();q.pop();
			if(curr == B)return cnt;
			for(int k = 0 ; k < 4; k++){
				auto plist = next_int(curr,k);
				for(auto j : plist){
					if(!visit[j]){
						q.push(j);
						visit[j] = true;
					}
				}
			}
		}
		cnt++;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int T;cin>>T;
	make_prime();
	while(T--){
		int A,B;
		cin>>A>>B;
		if(A == B){
			cout<<0<<endl;
			continue;
		}
		else{
			int cnt = bfs(A,B);
			if(cnt < 0){
				cout<<"Impossible/n";
			}
			else {
				cout<<cnt<<endl;
			}
		}
	}
}
