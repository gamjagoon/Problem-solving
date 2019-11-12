#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int>v;
int main(){
    int n,ch;
    scanf("%d",&n);
	v.reserve(n);
    for(int i = 0 ; i < n;++i){
        scanf("%d",&ch);
		v.push_back(ch);
    }
    make_heap (v.begin(),v.end());
	for(int i = v.back();i > 0;--i){
		printf("%d\n",v[i]);
	}
    return 0;
}