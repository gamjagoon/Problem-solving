#include <iostream>
#include <cstring>
using namespace std;
int map[504][504];
int result[2]={0,0};
int max(int n1,int n2){
    if(n1>n2)
        return n1;
    else return n2;
}
int sum_1(int h,int w){
    int ori=0;
    ori =max(ori, (map[h][w]+map[h][w+1]+map[h+1][w+1]+map[h+1][w+2]));
    ori =max(ori, (map[h+1][w]+map[h+1][w+1]+map[h][w+1]+map[h][w+2]));
    ori =max(ori, (map[h][w]+map[h+1][w]+map[h+1][w+1]+map[h+2][w+1]));
    ori =max(ori, (map[h+2][w]+map[h+1][w]+map[h+1][w+1]+map[h][w+1]));
    return ori;
}
int sum_2(int h,int w){
    int ori=0;
    ori = max(ori, (map[h][w]+map[h][w+1]+map[h+1][w+1]+map[h][w+2]));
    ori =max(ori, (map[h][w]+map[h+1][w+1]+map[h+1][w]+map[h+2][w]));
    ori =max(ori, (map[h+1][w]+map[h][w+1]+map[h+1][w+1]+map[h+1][w+2]));
    ori =max(ori,(map[h][w+1]+map[h+1][w]+map[h+1][w+1]+map[h+2][w+1]));
    return ori;
}
int sum_3(int h,int w){
    int ori=0;
    ori = max(ori, (map[h][w]+map[h][w+1]+map[h+1][w]+map[h][w+2]));
    ori =max(ori, (map[h][w]+map[h][w+1]+map[h+1][w+1]+map[h+2][w+1]));
    ori =max(ori, (map[h][w]+map[h+1][w]+map[h+1][w+1]+map[h+1][w+2]));
    ori =max(ori,(map[h][w]+map[h+1][w]+map[h+2][w]+map[h][w+1]));
    ori = max(ori, (map[h+1][w]+map[h+1][w+1]+map[h+1][w+2]+map[h][w+2]));
    ori =max(ori, (map[h][w]+map[h+1][w]+map[h+2][w]+map[h+2][w+1]));
    ori =max(ori, (map[h][w]+map[h][w+1]+map[h][w+2]+map[h+1][w+2]));
    ori =max(ori,(map[h+2][w]+map[h+2][w+1]+map[h+1][w+1]+map[h][w+1]));
    return ori;
}
void find_big(int N, int M){
    int ori=0;
    for(int h=0;h<N;h++){
        for(int w =0;w<M;w++){
            /*part 1*/
            ori=max(ori,(map[h][w]+map[h+1][w]+map[h][w+1]+map[h+1][w+1]));
            /*part 2*/
            ori=max(ori,(map[h][w]+map[h][w+1]+map[h][w+2]+map[h][w+3]));
            ori=max(ori,(map[h][w]+map[h+1][w]+map[h+2][w]+map[h+3][w]));
            /*part 3*/
            ori=max(ori,sum_1(h,w));
            /*part 4*/
            ori=max(ori,sum_2(h,w));
            /*part 5*/
            ori=max(ori,sum_3(h,w));
        }
    }
    result[0]= ori;
}
int main(){
    int N,M;
    int ori=0;
    // for(int i =1; i<20;i++){
    cin>>N>>M;
    memset(map,-1,sizeof(map));
    for(int h=0;h<N;h++)
    {
        for(int w=0;w<M;w++)
        {
            cin >> map[h][w];
        }
    }
    find_big(N,M);
    // cout<<i<<" = ";
    cout<<result[0]<<endl;
    // }
}