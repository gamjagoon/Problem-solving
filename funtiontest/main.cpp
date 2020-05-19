#include <iostream>
#include <array>
#include "./include/RotateArr.h"
#define endl '\n'

using namespace std;

//Global
array<array<int,101>,101>arr;
int R,C;

int main() {
  cin>>R>>C;
  for(int i = 1; i <= R; i ++){
    for(int j = 1; j <= C; j++){
      cin>>arr[i][j];
    }
  }
  view_arr(arr,R,C);
  box_rotate_left(arr,R,C);
  box_rotate_left(arr,R,C);
  box_rotate_left(arr,R,C);
  box_rotate_left(arr,R,C);
  rotate_left(arr,R,C);
  rotate_left(arr,R,C);
  rotate_left(arr,R,C);
  rotate_left(arr,R,C);

  view_arr(arr,R,C);
}