#include<iostream>
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
#define endl '\n'
using namespace std;

int R,C;
char arr[10][10];

template <typename T>
void mswap(T &a, T &b){
	T tmp = b;
	b = a;
	a = tmp;
}

void view_map(char m[10][10]){
	mfor(r,0,R-1){
		mfor(c,0,C-1){
			cout<<m[r][c]<<' ';
		}cout<<endl;
	}cout<<endl;
}

void cpy(char a[10][10],char b[10][10]){
	mfor(r,0,R-1){
		mfor(c,0,C-1){
			a[r][c] = b[r][c];
		}
	}
}

void rot_right(char arr[10][10]){
	char tmp[10][10];
	for(int i = 0; i < R; ++i){
		for(int j = 0 ; j < C; ++j){
			tmp[j][R-i-1] = arr[i][j];
		}
	}
	mswap(R,C);
	cpy(arr,tmp);
}

int main(){
	cin>>R>>C;
	mfor(r,0,R-1){
		mfor(c,0,C-1){
			cin>>arr[r][c];
		}
	}
	view_map(arr);
	rot_right(arr);
	view_map(arr);
}