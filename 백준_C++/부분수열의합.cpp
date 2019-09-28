#include <iostream>
#include <cstdio>

#define endl '\n'
#define BUF_SIZE 21
using namespace std;

int N,S;
int numbers[BUF_SIZE];
int count = 0;

void Input_Data(){
    cin>>N>>S;
    for(int i = 0; i < N;i ++){
        cin>>numbers[i];
    }

}
void dfs(int idx,int sum){
    sum += numbers[idx];
    if(idx >= N){return;}
    if(sum == S) //조건만족시
    {
        count++;
        // return; //이 조건이 붙으면 정답에서 탑색 범위가 줄어들어 count 의 크기가 줄어들게 되어있다
    }
    dfs(idx+1,sum-numbers[idx]);
    dfs(idx+1,sum);
}
int main(){
    Input_Data();
    dfs(0,0);
    cout<<count<<endl;
    return 0;
}
