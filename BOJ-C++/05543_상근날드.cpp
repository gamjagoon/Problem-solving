#include <iostream>
#define Loop(i,s,e) for(auto i = s; i < e;++i)
using namespace std;

int main() {
    int ham[3];
    int um[2];
    Loop(i,0,3){
        cin>>ham[i];
    }
    Loop(i,0,2){
        cin>>um[i];
    }
    int res = 1000000009;
    Loop(i,0,3){
        Loop(j,0,2){
			int tmp = ham[i] + um[j] - 50;
			res = res > tmp ? tmp : res;
		}
    }
	cout<<res;
}