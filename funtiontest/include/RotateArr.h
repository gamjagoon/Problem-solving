#pragma once
#include <iostream>
#include <array>
#include <algorithm>
#define SIZE 101
using namespace std;

array<array<int,SIZE>,SIZE>tmp;
typedef array<array<int,SIZE>,SIZE> Type;

void view_arr(Type &arr,int R, int C){
  for(int r = 1;r <= R;r++){
    for(int c = 1;c <= C;c++){
      cout<< arr[r][c]<<' ';
    }cout<<"\n";
  }cout<<"\n";
}

void dup_arg1(Type &arg1,int R,int C){
  for(int r = 1;r <= R;r++){
    for(int c = 1;c <= C;c++){
      arg1[r][c] = tmp[r][c];
    }
  }
}

void rotate_right(array< array<int,SIZE>, SIZE>&arr,int& R,int& C){
  swap(R,C);
  for(int r =1; r<= R;r++){
    for(int c=1,k = C; c<= C;c++,k--){
      tmp[r][c] = arr[k][r];
    }
  }
  dup_arg1(arr,R,C);
}

void rotate_left(array< array<int,SIZE>, SIZE>&arr,int& R,int& C){
  swap(R,C);
  for(int r =1,k=R; r<= R;r++,k--){
    for(int c=1; c<= C;c++){
      tmp[r][c] = arr[c][k];
    }
  }
  dup_arg1(arr,R,C);
}

void verticle_reverse(array< array<int,SIZE>, SIZE >&arr,int R,int C){
  for(int c = 1;c <= C;c++){
    for(int r = 1,k = R;r <= R;r++,k--){
      tmp[r][c] = arr[k][c];
    }
  }
  dup_arg1(arr,R,C);
}

void horizen_reverse(array< array<int,SIZE>, SIZE >&arr,int R,int C){
  for(int c = 1,k = C; c <= C;c++,k--){
    for(int r = 1; r <= R; r++){
      tmp[r][c] = arr[r][k];
    }
  }
  dup_arg1(arr,R,C);
}

void box_rotate_right(Type &arr,int R,int C)
{
  int rm = R/2,cm = C/2;
  for(int r = 1,k = rm+1; r <= rm;r++,k++){
    for(int c = 1; c <= cm;c++){
      tmp[r][c] = arr[k][c];
    }
  }
  for(int r = 1; r <= rm;r++){
    for(int c = cm+1,k = 1; c <= C;c++,k++){
      tmp[r][c] = arr[r][k];
    }
  }
  for(int r = rm+1; r <= R;r++){
    for(int c = 1,k = rm+1; c <= cm;c++,k++){
      tmp[r][c] = arr[r][k];
    }
  }
  for(int r = rm+1,k=1; r <= R;r++,k++){
    for(int c = cm+1; c <= C;c++){
      tmp[r][c] = arr[k][c];
    }
  }
  dup_arg1(arr,R,C);
}

void box_rotate_left(Type &arr,int R,int C)
{
  int rm = R/2,cm = C/2;
  for(int r = 1; r <= rm;r++){
    for(int c = 1,k = rm+1; c <= cm;c++,k++){
      tmp[r][c] = arr[r][k];
    }
  }
  for(int r = 1,k = rm+1; r <= rm;r++,k++){
    for(int c = cm+1; c <= C;c++){
      tmp[r][c] = arr[k][c];
    }
  }
  for(int r = rm+1,k = 1; r <= R;r++,k++){
    for(int c = 1; c <= cm;c++){
      tmp[r][c] = arr[k][c];
    }
  }
  for(int r = rm+1; r <= R;r++){
    for(int c = cm+1,k=1; c <= C;c++,k++){
      tmp[r][c] = arr[r][k];
    }
  }
  dup_arg1(arr,R,C);
}