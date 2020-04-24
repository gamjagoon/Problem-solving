#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#define INF 1000000009
#define endl '\n'

using namespace std;

//Global
string const strs[8] = {
	"000000","001111","010011","011100",
	"100110","101001","110101","111010"
};
string const res = "ABCDEFGH";

int solve(string &cur){
	int ret = 0;
	vector<pair<int,int>> res;
	for(int i = 0 ;  i < 8 ; i++){
		int cnt = 0;
		for(int j = 0; j < strs[i].size();j++){
			if(cur[j] != strs[i][j])++cnt;
		}
		if(cnt == 0){
			return i;
		}
		else res.push_back(make_pair(i,cnt));
	}
	sort(res.begin(),res.end(),[](pair<int,int>&a,pair<int,int>&b){return a.second < b.second;});
	if(res[0].second == 1 && res[1].second != 1){
		return res[0].first;
	}
	else return 8;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;	
	string tmp;cin>>tmp;
	int s = 0;
	string result = "";
	for(int i = 1; i <= t; i++){
		string curr{""};
		int cnt = 0;
		for(;cnt < 6;++cnt){
			curr += tmp[s+cnt];
		}
		s += cnt;
		int loc = solve(curr);
		if(loc == 8){
			cout<<i;
			return 0;
		}else{
			result += res[loc];
		}
	}
	cout<<result;
}
