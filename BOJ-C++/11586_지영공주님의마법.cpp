/*
Date : 05/25/2020
version : gcc 9.2.0 c++17
problem : 
summary : roatearr
*/
#include <iostream>
#define endl '\n'
using namespace std;

//Global
char arr[101][101];
int N;
void print_one(){
  for(int r = 0; r < N; r++){
    for(int c = 0; c < N; c++){
      cout<<arr[r][c];
    }cout<<endl;
  }
}
void print_two(){
  for(int r = 0; r < N; r++){
    for(int c = N-1; c >= 0; c--){
      cout<<arr[r][c];
    }cout<<endl;
  }
}
void print_tree(){
  for(int r = N-1; r >= 0; r--){
    for(int c = 0; c < N; c++){
      cout<<arr[r][c];
    }cout<<endl;
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  for(int i = 0; i < N; i++){
    cin>>arr[i];
  }
  int t;cin>>t;
  if(t == 1){
    print_one();
  }else if(t==2){
    print_two();
  }else{
    print_tree();
  }
}