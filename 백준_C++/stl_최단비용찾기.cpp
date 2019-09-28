#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int way[10][10];

bool RouteIsRight(vector<int>& v){
    for (int i = 1; i < v.size(); ++i){
        if(way[v[i-1]][v[i]] <= 0)
            return false;
    }
    if(way[v[v.size() - 1]][v[0]]<=0){
        return false;
    }
    return true;
}

int CalcCost(vector<int>& v){
    int cost = 0;
    for(int i = 1;i < v.size(); ++i){
        cost += way[v[i-1]][v[i]];
    }
    cost += way[v[v.size()-1]][v[0]];
    return cost;
}

int main(){
    int n;
    cin >> n;
    vector<int> city(n);
    for(int i = 0;i < n; ++i){
        city[i] = i;
    }
    for(int i = 0;i < n; ++i){
        for(int j =0; j < n;++j){
            cin >> way[i][j];
        }
    }
    int ans = __INT_MAX__;
    do{
        if(RouteIsRight(city)){
            ans = min(ans,CalcCost(city));
        }
    }while (next_permutation(city.begin(),city.end()));
    cout<<ans;
    return 0;
}