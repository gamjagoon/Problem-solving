#include <iostream>
#include <cstring>
using namespace std;
int cnt_A[255];
int cnt_B[255];

int main()
{
	memset(cnt_A,0,sizeof(cnt_A));
	memset(cnt_B,0,sizeof(cnt_B));
	string a;
	cin>>a;
	for (auto i : a) {
		cnt_A[i] += 1;
	}
	cin>>a;
	for (auto i : a) {
		cnt_B[i] += 1;
	}
	int result = 0;
	for (int i = 'a'; i <= 'z'; ++i) {
		if(cnt_A[i] >= cnt_B[i])result += cnt_A[i]-cnt_B[i];
		else result += cnt_B[i] - cnt_A[i];
	}
	cout<<result;
	return 0;
}