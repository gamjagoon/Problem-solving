/*
Date : 05/23/2020
version : gcc 9.2.0 c++17
problem : 
summary : bfs
*/
#include <iostream>
#include <array>
#define endl '\n'
#define ONE true
#define TWO false
using namespace std;
constexpr char case1 = '/';
struct cb{
  int c;
  bool b;
};
typedef array< array<cb,501>, 501> mtype;

//Global
int R,C;
mtype arr;

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>R>>C;
  if((R % 2 + C %2) == 1){
    cout<<"NO SOLUTION";
    return 0;
  }
  for(int r = 0; r < R; r++){
    string tmp;
    cin>>tmp;
    for(int c = 0; c < C; c++){
      if(tmp[c] == case1){
        arr[r][c] = {0,ONE};
      }else{
        arr[r][c] = {0,TWO};
      }
    }
  }

  
}