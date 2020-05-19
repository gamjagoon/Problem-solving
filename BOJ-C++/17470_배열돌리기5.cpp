/*
Date : 05/15/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/17470
summary : 구현
*/
#include <iostream>
#include <vector>
#include <array>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
#define SIZE 101
//Global
int R,C,T;
typedef array< array<int,51>,51> Type;
typedef array< array<Type, 2>, 2> Box;
Type tmp;
Box arr;
Box tmparr;

void view_arr(){
  for(int i = 0; i < 2;i++){
    for(int r = 1; r <= R;r++){
      for(int c = 1; c <= C; c++){
        cout<<arr[i][0][r][c]<<' ';
      }
      for(int c = 1; c <= C; c++){
        cout<<arr[i][1][r][c]<<' ';
      }cout<<endl;
    }
  }
}

void dup_arg1(Type &arg1){
  for(int r = 1;r <= R;r++){
    for(int c = 1;c <= C;c++){
      arg1[r][c] = tmp[r][c];
    }
  }
}

void rotate_right(Type&arr){
  for(int r =1; r<= R;r++){
    for(int c=1,k = C; c<= C;c++,k--){
      tmp[r][c] = arr[k][r];
    }
  }
  dup_arg1(arr);
}

void right_rot(int &R,int &C){
  swap(R,C);
  for(int i = 0; i < 2;i++){
    for(int j = 0; j < 2;j++){
      rotate_right(arr[i][j]);
    }
  }
}

void rotate_left(Type&arr){
  for(int r =1,k=R; r<= R;r++,k--){
    for(int c=1; c<= C;c++){
      tmp[r][c] = arr[c][k];
    }
  }
  dup_arg1(arr);
}

void left_rot(int &R,int &C){
  swap(R,C);
  for(int i = 0; i < 2;i++){
    for(int j = 0; j < 2;j++){
      rotate_left(arr[i][j]);
    }
  }
}

void verticle_reverse(Type&arr){
  for(int c = 1;c <= C;c++){
    for(int r = 1,k = R;r <= R;r++,k--){
      tmp[r][c] = arr[k][c];
    }
  }
  dup_arg1(arr);
}

void horizen_reverse(Type&arr){
  for(int c = 1,k = C; c <= C;c++,k--){
    for(int r = 1; r <= R; r++){
      tmp[r][c] = arr[r][k];
    }
  }
  dup_arg1(arr);
}

void verticle(){
  for(int i = 0; i < 2;i++){
    for(int j = 0; j < 2;j++){
      verticle_reverse(arr[i][j]);
    }
  }
}

void horizen(){
  for(int i = 0; i < 2;i++){
    for(int j = 0; j < 2;j++){
      horizen_reverse(arr[i][j]);
    }
  }
}


void box_rotate_right()
{
  for(int r =0; r< 2;r++){
    for(int c=0,k = 2; c< 2;c++,k--){
      tmparr[r][c] = move(arr[k][r]);
    }
  }
  for(int r =0; r< 2;r++){
    for(int c=0; c< 2;c++){
      arr[r][c] = move(tmparr[r][c]);
    }
  }
}

void box_rotate_left()
{
  for(int r =0,k=2; r< 2;r++,k--){
    for(int c=0; c< 2;c++){
      tmparr[r][c] = move(arr[c][k]);
    }
  }
  for(int r =0; r< 2;r++){
    for(int c=0; c< 2;c++){
      arr[r][c] = move(tmparr[r][c]);
    }
  }
}

bool ver = false;
bool hor = false;
bool riv = false;
int r_rot = 0;
int box_right = 0;


void query_input(){
  int tmp;
  Loop(i,0,T){
    cin>>tmp;
    if(tmp == 1){
      riv = riv ? false : true;
      ver = ver ? false : true;
      r_rot = -r_rot;
      box_right = -box_right;
    }
    else if(tmp ==2){
      riv = riv ? false : true;
      hor = hor ? false : true;
      r_rot = -r_rot;
      box_right = -box_right;
    }
    else if(tmp == 3){ 
      if(riv)r_rot--;
      else r_rot++;
    }
    else if(tmp == 4){
      if(riv)r_rot++;
      else r_rot--;
    }
    else if(tmp == 5){
      if(riv)box_right--;
      else box_right++;
    }else {
      if(riv)box_right++;
      else box_right--;
    }
  }
}

void query_calc(){
  if(box_right < 0){
    box_right *= -1;
    box_right %= 4;
    for(int i = 0; i < box_right;i++){
      box_rotate_left();
    }
  }else{
    box_right %= 4;
    for(int i = 0; i < box_right;i++){
      box_rotate_right();
    }
  }
  if(hor){
    horizen();
  }
  if(ver){
    verticle();
  }
  if(r_rot < 0){
    r_rot *= -1;
    r_rot %= 4;
    for(int i = 0; i < r_rot;i++){
      left_rot(R,C);
    }
  }else{
    r_rot %= 4;
    for(int i = 0; i < r_rot;i++){
      right_rot(R,C);
    }
  }
}

int main() {
  io;
  cin>>R>>C>>T;
  R /= 2;
  C /= 2;
  for(int i = 0; i < 2;i++){
    for(int r = 1; r <= R;r++){
      for(int c = 1; c <= C; c++){
        cin>>arr[i][0][r][c];
      }
      for(int c = 1; c <= C; c++){
        cin>>arr[i][1][r][c];
      }
    }
  }
  query_input();
  query_calc();
  view_arr();
}