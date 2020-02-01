/*
Date : 02/01/2020
version : gcc 6.3.0 c++14
problem : 낚시왕
summary : 구현 시뮬레이션
*/
#include <iostream>
#include <queue>
#include <cstring>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
int R,C,M,cnt = 0,res = 0;

class shark {
public:
int _r,_c,_speed,_sz,_dir;
shark(){};
shark(int r,int c,int spd,int d,int z){
	this->_r = r;
	this->_c = c;
	this->_speed = spd;
	this->_dir = d;
	this->_sz = z;
}
~shark(){};
shark* move_shark(){
	int var_1,spd = this->_speed,m,l;
	switch (this->_dir)
	{
	case 1://위로 이동할때
		if(this->_r - spd > 1){
			this->_r -= spd;
		}
		else{
			spd  -= this->_r - 1;
			var_1 = R - 1;
			m = spd % var_1;
			l = spd / var_1;
			if(l % 2 == 1)//홀수 몫 일때 방향 전화 방향전화 ㄴ
			{
				this->_r  = R - m;
			}
			else{
				this->_dir = 2;
				this->_r = 1 + m;
			}
		}
		break;
	case 2://아래로 이동할때
		if(this->_r + spd < R){
			this->_r += spd;
		}
		else{
			spd  -= R - this->_r;
			var_1 = R - 1;
			m = spd % var_1;
			l = spd / var_1;
			if(l % 2 == 1)//홀수 몫 일때 방향 전화 방향전화 ㄴ
			{
				this->_r  =1 + m;
			}
			else{
				this->_dir = 1;
				this->_r =R - m;
			}
		}
		break;
	case 3://오른쪽 이동할때
		if(this->_c + spd < C){
			this->_c += spd;
		}
		else{
			spd  -= C - this->_c;
			var_1 = C - 1;
			m = spd % var_1;
			l = spd / var_1;
			if(l % 2 == 1)//홀수 몫 일때 방향 전화 방향전화 ㄴ
			{
				this->_c  =1 + m;
			}
			else{
				this->_dir = 4;
				this->_c =C - m;
			}
		}
		break;
	default://왼쪽으로 이동할때
		if(this->_c - spd > 1){
			this->_c -= spd;
		}
		else{
			spd  -= this->_c - 1;
			var_1 = C - 1;
			m = spd % var_1;
			l = spd / var_1;
			if(l % 2 == 1)//홀수 몫 일때 방향 전화 방향전화 ㄴ
			{
				this->_c  = C - m;
			}
			else{
				this->_dir = 3;
				this->_c = 1 + m;
			}
		}
		break;
	}
	return this;
}
};

shark *real[101][101];

void all_move(){
	shark *tmp[101][101];
	memset(tmp,NULL,sizeof(tmp));
	shark* now;
	mfor(r,1,R){
		mfor(c,1,C){
			if(real[r][c] == NULL)continue;
			now = real[r][c]->move_shark();
			if(tmp[now->_r][now->_c] != NULL){
				if(tmp[now->_r][now->_c]->_sz < now->_sz){
					tmp[now->_r][now->_c] = now;
					cnt--;
				}
			}
			else{
				tmp[now->_r][now->_c] = now;
			}
		}
	}
	mfor(r,1,R){
		mfor(c,1,C){
			real[r][c] = tmp[r][c];
		}
	}
}

void kill_shark(int n){
	shark *now;
	mfor(r,1,R){
		if(real[r][n] != NULL){
			now = real[r][n];
			real[r][n] = NULL;
			res+= now->_sz;
			now->~shark();
			break;
		}
	}
}

void view_shark(){
	mfor(r,1,R){
		mfor(c,1,C){
			if(real[r][c] != NULL){
				switch (real[r][c]->_dir)
				{
				case 1:
					cout<<"^"<<real[r][c]->_sz<<" ";
					break;
				case 2:
					cout<<"v"<<real[r][c]->_sz<<" ";
					break;
				case 3:
					cout<<">"<<real[r][c]->_sz<<" ";
					break;
				default:
					cout<<"<"<<real[r][c]->_sz<<" ";
					break;
				}
			}
			else{
				cout<<"x  ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
}

void solve(){
	for(int i = 1; i <= C; ++i){
		kill_shark(i);
		if(cnt <= 0)break;
		all_move();
	}
	cout<<res;
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>R>>C>>M;
	int r,c,s,d,z;
	int pos = 0;
	mfor(i,0,M-1){
		cin>>r>>c>>s>>d>>z;
		real[r][c] = new shark(r,c,s,d,z);
		cnt++;
	}
	solve();
	return 0;
}