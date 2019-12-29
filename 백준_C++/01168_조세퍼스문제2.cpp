#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int seg[410000];
int n, m;
vector <int> ans;

//*idx 값이 변한다 val 은 1로 고정 
//*트리를 구간의 합으로 정의
int init(int idx, int val, int node, int s,int e) {
	if(idx < s || e < idx)return seg[node]; //만약 idx 가 범위 밖에면 그대로 리턴
	if(s == e)return seg[node] = val; // 같다면 트리에 값 저장
	int m = (s + e) >> 1;
	return seg[node] = init(idx,val,node*2,s,m) + init(idx,val,node*2+1,m+1,e);
}

//*시작노드부터 이분 탐색 시작
//*val 이거나 val 보다 큰 세그 트리의 합을 리턴
int query(int val, int node, int s, int e) {
	if(s == e) return s;
	if(seg[node * 2] >= val) return query(val, node*2, s, (s + e)/2);
	else return query(val-seg[node*2],node*2+1,(s+e)/2+1,e);
}

//*구간의 합 1 1 1 1 1 1 1 -> 1 1 0 1 1 1 1 경우
//* sum_query(1,3,1,1,n) = 3 -> 2 로 줄어든다
int sum_query(int lo, int hi, int node, int s, int e) {
	if(e < lo || hi < s)return 0;
	if(lo <= s && e <= hi)return seg[node];
	int m = (s + e)>>1;
	return sum_query(lo,hi,node*2,s,m) + sum_query(lo,hi,node*2+1,m+1,e);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; ++i)
	{
		init(i, 1, 1, 1, n);
	}
	
	int mod = n - 1;
	ans.push_back(m);//m 번째 사람미리 제거
	init(m, 0, 1, 1, n);

	for(int i = 2; i <= n; i++) {
		int x = (sum_query(1,ans.back(),1,1,n) + m) % mod;
		if(!x) x = mod;
		ans.push_back(query(x,1,1,n));
		init(ans.back(),0,1,1,n);
		mod--;
	}

	cout<<'<';
	for(auto i : ans){
		if(i != ans.back())
			cout<<i<<", ";
	}
	cout<<ans.back();
	cout<<">\n";
	return 0;
}