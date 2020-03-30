#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int F[1000001];

int solve(string &str,int n) {
	int j = 0;
	for (int i = 1; i < n; ++i) {
		while(j > 0 && str[i] != str[j])j = F[j-1];
		if (str[j] == str[i]) {
			F[i] = j+1;
			j++;
		}
	}
	return n-F[n-1];
}
int main()
{
	int N;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string str;
	cin>>N;
	cin>>str;
	cout<<solve(str,N);
	return 0;
}