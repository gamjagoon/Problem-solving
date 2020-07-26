#include <iostream>
#include <algorithm>
using namespace std;

int map[504][504];

int find_big(int N, int M){
    int ret=0;
    for(int h=0;h<N;h++){
        for(int w =0;w<M;w++){
			ret=max(ret,(map[h][w]+map[h+1][w]+map[h][w+1]+map[h+1][w+1]));

			ret=max(ret,(map[h][w]+map[h][w+1]+map[h][w+2]+map[h][w+3]));
            ret=max(ret,(map[h][w]+map[h+1][w]+map[h+2][w]+map[h+3][w]));

			ret =max(ret, (map[h][w]+map[h][w+1]+map[h+1][w+1]+map[h+1][w+2]));
			ret =max(ret, (map[h+1][w]+map[h+1][w+1]+map[h][w+1]+map[h][w+2]));
			ret =max(ret, (map[h][w]+map[h+1][w]+map[h+1][w+1]+map[h+2][w+1]));
			ret =max(ret, (map[h+2][w]+map[h+1][w]+map[h+1][w+1]+map[h][w+1]));
			ret = max(ret, (map[h][w]+map[h][w+1]+map[h+1][w+1]+map[h][w+2]));;
			ret =max(ret, (map[h][w]+map[h+1][w+1]+map[h+1][w]+map[h+2][w]));
			ret =max(ret, (map[h+1][w]+map[h][w+1]+map[h+1][w+1]+map[h+1][w+2]));
			ret =max(ret,(map[h][w+1]+map[h+1][w]+map[h+1][w+1]+map[h+2][w+1]));
			ret = max(ret, (map[h][w]+map[h][w+1]+map[h+1][w]+map[h][w+2]));
			ret =max(ret, (map[h][w]+map[h][w+1]+map[h+1][w+1]+map[h+2][w+1]));
			ret =max(ret, (map[h][w]+map[h+1][w]+map[h+1][w+1]+map[h+1][w+2]));
			ret =max(ret,(map[h][w]+map[h+1][w]+map[h+2][w]+map[h][w+1]));
			ret = max(ret, (map[h+1][w]+map[h+1][w+1]+map[h+1][w+2]+map[h][w+2]));
			ret =max(ret, (map[h][w]+map[h+1][w]+map[h+2][w]+map[h+2][w+1]));
			ret =max(ret, (map[h][w]+map[h][w+1]+map[h][w+2]+map[h+1][w+2]));
			ret =max(ret,(map[h+2][w]+map[h+2][w+1]+map[h+1][w+1]+map[h][w+1]));
        }
    }
	return ret;
}

int main(){
    int N,M;
	ios::sync_with_stdio(false);cin.tie(0);
    cin>>N>>M;
    for(int h=0;h<N;h++)
    {
        for(int w=0;w<M;w++)
        {
            cin >> map[h][w];
        }
    }
    cout<<find_big(N,M);
}
