#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permu(vector<int>&a,int SetSize,int n){
  if(SetSize == n){
    for(auto &i : a)cout<<i<<' ';
    cout<<endl;
    return;
  }
  for(int i = SetSize; i < n;i++){
    swap(a[i],a[SetSize]);
    permu(a,SetSize+1,n);
    swap(a[i],a[SetSize]);
  }
}

int main(){
  vector<int>tmp;
  for(int i = 1; i <= 4; ++i)tmp.push_back(i);
  permu(tmp,0,4);
}