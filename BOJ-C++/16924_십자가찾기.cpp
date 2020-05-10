/*
Date : 05/02/2020
version : gcc 9.2.0 c++17
decribe : 구현 
*/
#include <iostream>
#include <vector>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define INF 1000000009
#define io ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

struct rcv{
	int r,c,v;
};

char arr[101][101];
bool ch[101][101];
int R,C;
int M = 100;
vector<rcv>res;

void input();
bool check_end();
void check_cross(int r,int c,int v);
void remove_stars();


int main(){
	io;
	cin>>R>>C;
	M = R > M ? M : R;
	M = C > M ? M : C;
	input();
	Loop(r,0,R){
		Loop(c,0,C){
			check_cross(r,c,M);
		}
	}
	if(check_end()){
		cout<<res.size()<<endl;
		for(auto i : res){
			cout<<i.r+1<<' '<<i.c+1<<' '<<i.v<<'\n';
		}
	}
	else {
		cout<<"-1";
	}
}

void input(){
	Loop(r,0,R){
		cin>>arr[r];
		Loop(c,0,C){
			ch[r][c] = false;
		}
	}
}

bool check_end(){
	Loop(r,0,R){
		Loop(c,0,C){
			if(arr[r][c]  == '*' && !ch[r][c]){
				return false;
			}
		}
	}
	return true;
}

void check_cross(int r,int c,int v){
	if(v <= 0)return;
	if(r - v < 0 || r + v >= R || c - v < 0 || c + v >= C){
		#ifdef DEBUG
		if(r == 2 && c == 4){
			cout<<r - v<<' '<<r+v<<' '<<c-v<<' '<<c+v<<endl;
			cout<<"end call "<<v<<endl;
		}
		#endif	
		check_cross(r,c,v-1);
		return;
	}
	else {
		#ifdef DEBUG
		if(r == 2 && c == 4){
			cout<<"start call "<<v<<endl;
		}
		#endif
		bool flag = false;
		for(int i = r-v; i <= r + v; i++){
			if(arr[i][c] != '*'){
				flag = true;
				#ifdef DEBUG
		if(r == 2 && c == 4){
			cout<<i<<' '<<c<<"end call "<<v<<endl;
		}
		#endif
				break;
			}
		}
		if(flag){
			check_cross(r,c,v-1);
		}
		else {
			for(int i = c-v; i <= c + v; i++){
				if(arr[r][i] != '*'){
					#ifdef DEBUG
		if(r == 2 && c == 4){
			cout<<r<<' '<<i<<"end call "<<v<<endl;
		}
		#endif
					flag = true;
					break;
				}
			}
			if(flag){
				check_cross(r,c,v-1);
			}
			else {
				for(int i = c-v; i <= c + v; i++){
					ch[r][i] = true;
				}
				for(int i = r-v; i <= r + v; i++){
					ch[i][c] = true;
				}
				Loop(i,1,v+1){
					res.push_back({r,c,i});
				}
			}
		}
	}
}