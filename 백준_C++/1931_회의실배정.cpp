#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<pair<int,int>>D;
bool cmp(pair<int,int>a,pair<int,int>b){
	if (a.second == b.second){
		return a.first < b.first;
	}
	else{
		return a.second < b.second;
	}
}
int main(){
	scanf("%d",&N);
	int p;int s;
	for(int i = 0 ; i < N;++i){
		scanf("%d %d",&p,&s);
		D.push_back({p,s});
	}
	sort(D.begin(),D.end(),cmp);
	p = 0;int result = 0;
	for(int i = 0; i < D.size();++i){
		if(p <= D[i].first){
			p = D[i].second;
			result++;
		}
	}
	printf("%d",result);
}