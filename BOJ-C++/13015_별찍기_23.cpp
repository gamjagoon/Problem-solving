#include <iostream>
#define space cout << '\n';
using namespace std;
void top_bottom(int N)
{
	int t1 = N;
	int t2 = N;
	int s = 1 + 2 * (N - 2);
	while(t1--)
	{
		cout << '*';
	}
	while(s--){
		cout << ' ';
	}
	while(t2--){
		cout << '*';
	}
	space
}
void body(int N)
{
	int s1 = N - 1;
	int s2 = N - 2;
	int s3 = s2;
	int s4 = s1;
	while(s1--)
		cout << ' ';
	cout << '*';
	while(s2--)
		cout << ' ';
	cout << '*';
	while(s3--)
		cout << ' ';
	cout << '*';
	space
}

void midle(int N,int i)
{
	int s1 = i;
	int s2 = N - 2;
	int s3 = 1 + 2 * (N - 2) - i * 2;
	int s4 = s2;
	int s5 = s1;
	while(s1--)
		cout << ' ';
	cout << '*';
	while(s2--)
		cout << ' ';
	cout << '*';
	while(s3--)
		cout << ' ';
	cout << '*';
	while(s4--)
		cout << ' ';
	cout << '*';
	space
}
int main()
{
	int N;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int u = N - 2;
	int d = u;
	top_bottom(N);
	for (int i = 1; i <= u; ++i)
	{
		midle(N, i);
	}
	body(N);
	for (int j = d; j >= 1;--j)
	{
		midle(N, j);
	}
	top_bottom(N);
}
