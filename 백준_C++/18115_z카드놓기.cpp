#include <iostream>
#include <queue>
#include <vector>
using namespace std;

deque<int>res;
int N;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N;
	vector<int>arr(N+1);
	for(int i = 1; i <= N; ++i){
		cin>>arr[i];
	}
	int k = 1;
	for(int i = N; i >= 1;--i)
	{
		if(arr[i] == 1){
			res.push_front(k++);
		}
		else if(arr[i] == 2){
			if(!res.empty())
			{
			int a = res.front();
			res.pop_front();
			res.push_front(k++);
			res.push_front(a);
			}
			else{
				res.push_front(k++);
			}
		}
		else{
			res.push_back(k++);
		}
	}

	int sz = res.size();
	for(int i = 0 ; i < sz;++i)
	{
		cout<<res.front()<<' ';
		res.pop_front();
	}
	return 0;
}