#include <iostream>

using namespace std;

string A,B;
int lenA,lenB,e;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>A>>B;
	lenA = A.length();
	lenB = B.length();
	e = lenB - lenA ;
	int res = lenA;
	int cnt;
	for(int s = 0 ; s <= e ; ++s){
		cnt = 0;
		for(int i = 0; i < lenA;++i){
			if(B[i+s] != A[i]){
				cnt++;
			}
		}
		if(res > cnt)res = cnt;
		if(res == 0)break;
	}
	cout<<res;
	return 0;
}