#include <iostream>
using namespace std;
constexpr int a[3] = {300,60,10};
int res[3];
pair<int,int> f(int t,int b){
	pair<int,int> ret;
    ret.first = t / b;
    ret.second = t % b;
    return ret;
}
int main(){
    int t;cin>>t;
    if(t % 10)cout<<-1;
    else{
		for(int i = 0 ; i < 3 && t != 0;++i){
			auto [ret,nt] = f(t,a[i]);
			res[i] = ret; t = nt;
		}
    }
	for(auto i : res){cout<<i<<' ';}
}
