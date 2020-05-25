/*
Date : 05/25/2020
version : gcc 9.2.0 c++17
problem : 
summary : iplement
*/
#include <iostream>
#define endl '\n'
using namespace std;

//Global
char arr[101][101];
int N;

int solc(void){
  int result = 0;
  for (int i = 0; i < N; i++)
  {
    int cnt = 0;
    for (int j = 0; j < N; j++)
    {
      if (arr[i][j] == '.')cnt++;
      else if (arr[i][j] == 'X' && cnt >= 2)
      {
        result++;
        cnt = 0;
      }
      else if (arr[i][j] == 'X')cnt = 0;
    }
    if (cnt >= 2)result++;
  }
  return result;
}



int solr(void){
  int result = 0;
  for (int i = 0; i < N; i++)
  {
    int cnt = 0;
    for (int j = 0; j < N; j++)
    {
      if(arr[j][i] == '.')cnt++;
      else if (arr[j][i] == 'X' && cnt >= 2){
        result++;
        cnt = 0;
      }
      else if (arr[j][i] == 'X')cnt = 0;
    }
    if (cnt >= 2)result++;
  }
  return result;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  for(int i = 0; i < N; i++){
    cin>>arr[i];
  }
  cout<<solc()<<' '<<solr();
}