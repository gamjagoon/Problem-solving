#include <iostream>

using namespace std;

inline int m_Max(int &a,int &b){
	if(a > b)return a;
	else return b;
}

struct round{
	int a,b;
};
round T[302];
int N;

//가위를 1, 바위를 2, 보를 3
//1 > 2 
int solve()
{
	int res = 0;
	int t_a = 0;
	int t_b = 0;
	for(int i = 0 ; i < N; ++i)
	{
		if(T[i].a == T[i].b){
			if(t_a == 0){
				t_b = 0;
				t_a++;
				res = m_Max(res, t_a);
			}
			else{
				t_a = 0;
				t_b++;
				res = m_Max(res, t_b);
			}
			continue;
		}
		switch (T[i].a)
		{
		//가위
		case 1:
			if(T[i].b == 3){
				t_a++;
				res = m_Max(res,t_a);
				t_b = 0;
			}
			else{
				t_b++;
				res = m_Max(res,t_b);
				t_a = 0;
			}
			break;
		case 2:
			if(T[i].b == 1){
				t_a++;
				res = m_Max(res,t_a);
				t_b = 0;
			}
			else{
				t_b++;
				res = m_Max(res,t_b);
				t_a = 0;
			}
			break;
		//3
		default:
			if(T[i].b == 2){
				t_a++;
				res = m_Max(res,t_a);
				t_b = 0;
			}
			else{
				t_b++;
				res = m_Max(res,t_b);
				t_a = 0;
			}
			break;
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 0; i <N; ++i)
	{
		cin>>T[i].a;
	}
	for(int i = 0; i <N; ++i)
	{
		cin>>T[i].b;
	}
	cout << solve();
	return 0;
}