#include <iostream>
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
#define INF 100
using namespace std;

int N;
int arr[51][51];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>N;
	string tmp;
	mfor(i,1,N){
		cin>>tmp;
		mfor(j,1,N){
			if(tmp[j-1] == 'Y'){
				arr[i][j] = 1;
			}else{
				arr[i][j] = INF;
			}
		}
	}
	mfor(k,1,N){
		mfor(i,1,N){
			mfor(j,1,N){
				if(arr[i][j] > arr[i][k] + arr[k][j] && arr[i][k]+arr[k][j] == 2){
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	int res = 0;
	int cnt = 0;
	mfor(i,1,N){
		cnt = 0;
		mfor(j,1,N){
			if(arr[i][j] <= 2){
				cnt++;
			}
		}
		cnt--;
		if(res < cnt){
			res = cnt;
		}
	}
	cout<<res;
	return 0;
}