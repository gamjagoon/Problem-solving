#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,int>pli;
string list[50];
vector<pair<pli,ll>> number;int N;
int alpatonum[10];
ll result = 0;
ll result_2= 0;
bool com(pair<pli,ll>&a,pair<pli,ll>&b){
	if(a.first.first > b.first.first){
		return true;
	}
	else if(a.first.first == b.first.first){
		return a.first.second > b.first.second;
	}
	else{
		return false;
	}
}

void check(int target){
	bool in = false;
	for (int i = 0; i < N; i++){
		if (alpatonum[list[i][0] - 'A'] == 0){
			for (int j = 0; j < 10; j++){
				if (target == alpatonum[j]){
					alpatonum[j] = 0;
					alpatonum[list[i][0] - 'A'] = target;
					in = true;
					break;
				}
			}
		}
		if(in) break;
	}
	if (in == false) return;
	else check(++target);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 0 ; i <10;++i)
	{
		alpatonum[i] = 0;
		number.push_back(make_pair(pli(0,0),i));
	}
	int sz;
	for(int i = 0 ; i < N;++i)
	{
		cin>>list[i];
		
		ll k = 1;
		sz = list[i].size();
		for(int j = sz-1; j >= 0; --j){
			number[list[i][j]-'A'].first.first+=k;
			number[list[i][j]-'A'].first.second+=j;
			k*=10;
		}
	}
	sort(number.begin(),number.end(),com);
	int num = 9;
	for(auto v : number){
		alpatonum[v.second] = num--;
	}
	check(1);
	for(int i = 0 ; i< N;++i)
	{
		ll stmp = 0;
		sz = list[i].size();
		for(int j = 0; j < sz;++j)
		{
			stmp*=10;
			stmp += alpatonum[list[i][j]-'A'];
		}
		result += stmp;
	}
	cout<<result;
	return 0;
}