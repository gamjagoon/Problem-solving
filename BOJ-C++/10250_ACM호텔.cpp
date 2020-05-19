#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  int N;cin>>N;
  while(N--){
    int N,H,W;
    cin>>H>>W>>N;
    int r = N%H;
    int c = N/H;
    c++;
    if(r == 0){
      r = H;
      c-=1;
    }
    if(c < 10){
      cout<<r<<'0'<<c<<"\n";
    }else{
      cout<<r<<c<<"\n";
    }
  }
}