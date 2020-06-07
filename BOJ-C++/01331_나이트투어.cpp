
/*
Date : 06/07/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1331
summary : 시뮬
*/
#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

//Global
int board[6][6];
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,-2,-1,1,2};
bool moveable(int x1, int y1, int x2, int y2)
{
  for (int j = 0; j < 8; j++)
  {
      int mx = x1 + dx[j];
      int my = y2 + dy[j];
      if (mx < 0 || mx >= 6 || my < 0 || my >= 6) continue;
      if (mx == x2 && my == y2) {
        return true;
      }
  }
}
bool valid(string& s1, string &s2)
{
    int x = s2[0] - 'A';
    int y = s2[1] - '1';
    if (board[x][y] != 0)return false;
    board[x][y] = 1;
    return moveable(s1[0] - 'A', s1[1] - '1',x,y);
}
 
int main()
{
    string input[36];
    for(int i = 0; i < 36; i++){
      cin>>input[i];
    }
    int x = input[0][0] - 'A';
    int y = input[0][1] - '1';
    board[x][y] = 1;
    for (int i = 1; i < 36; i++)
    {
        string& str1 = input[i-1];
        string& str2 = input[i];
        if (!valid(str1, str2))
        {
            cout<<"Invalid";
            return 0;
        }
    }
    bool flag = false;
    for (int j = 0; j < 8; j++) {
        int aa = (input[0][0] - 'A') + dx[j];
        int bb = (input[0][1] - '1') + dy[j];
        if (aa < 0 || aa>5 || bb < 0 || bb>5)continue;
        if (aa == (input[35][0] - 'A') && bb == (input[35][1] - '1'))flag = true;
    }
    if (!flag){
      cout<<"Invalid";
      return 0;
    }
    cout<<"Valid";
}
