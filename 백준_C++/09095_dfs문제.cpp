#include <iostream>
using namespace std;

int dfs(int n){ 
    if(n == 0) return 1;  
    int ret = 0; 
    if(n - 1 >= 0) ret += dfs(n - 1);
    if(n - 2 >= 0) ret += dfs(n - 2);
    if(n - 3 >= 0) ret += dfs(n - 3);
    return ret;  
}
int main(){
    int N;
    cin>>N;
    int num;
    for(int i =0;i<N;i++){
        cin>>num;
        cout<<dfs(num)<<"\n";
    }
}