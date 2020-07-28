#include <iostream>
#include <queue>
using namespace std;

queue<int>upone;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int N;cin>>N;
	int S = 0;
	int zcnt = 0;
	int tmp;
	for(int i = 0 ; i < N;i++){
		cin>>tmp;
		if(tmp == 1){
			zcnt++;
		}else if(tmp > 1){
			upone.push(tmp);
			S += tmp;
		}
		while(!upone.empty() && zcnt > 0){
			int c = upone.front();
			upone.pop();
			c -= 2;--zcnt;
			S -= 2;
			if(c == 1){
				zcnt++;
				--S;
			}
			else if(c > 1 )upone.push(c);
		}
	}
	while(!upone.empty() && zcnt > 0){
		int c = upone.front();
		upone.pop();
		c -= 2;--zcnt;
		S -= 2;
		if(c == 1){
			zcnt++;
			--S;
		}
		else if(c > 1 )upone.push(c);
	}
	if(zcnt > 0 || S % 3 != 0){
		cout<<"NO";
	} else {
		cout<<"YES";
	}
}
