#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int N,K;
string A("");
queue<string>v;
bool hashtable[87654322] = {false};

bool is_good(string& v)
{
	for(auto i = 0; i < N-1;++i){
		if(v[i+1] < v[i])return false;
	}
	return true;
}

string r_str(string a,int s)
{
	int e = s + K; // 4
	int m = K/2;
	char tmp;
	for(int i = 0 ; i <= m ; ++i ){
		tmp = a[i+s];
		a[i+s] = a[e-i];
		a[e-i] = tmp;
	}
	return a;
}

int to_hash(string &a){
	int code = 0;
	for(int i = 0 ; i < N;++i){
		code *= 10;
		code += a[i] - '0';
	}
	return code;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>K;
	for(auto i = 0 ; i< 87654322;++i)hashtable[i] = false;
	K--;
	char tmp;
	for(int i = 0 ; i < N;++i){
		cin>>tmp;
		A+=tmp;
	}
	bool find = false;
	int cnt = 0;
	int end = N - K;
	if(is_good(A))find = true;
	else{
		v.push(A);
	}
	hashtable[to_hash(A)] = true;
	while(!find && !v.empty())
	{
		int s = v.size();
		cnt++;
		for(int i = 0 ; i < s;++i){
			string now = v.front();v.pop();
			for(int j = 0 ; j < end ; ++j)
			{
				string tmp= r_str(now,j);
				int code = to_hash(tmp);
				if(hashtable[code]){
					continue;
				}
				else{
					hashtable[code] = true;
					if(is_good(tmp)){
						find = true;
						break;
					}
					v.push(tmp);
				}
			}
			if(find)break;
		}
	}
	if(find)cout<<cnt;
	else cout<<-1;
	return 0;
}


