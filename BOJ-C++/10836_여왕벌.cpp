/*
Date : 05/14/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/10836
summary : 시뮬 구현
*/
#include <cstdio>
int M,N;
int arr[1500];

char in[1<<25]; // sizeof in varied in problem
char const*o;

void init_in()
{ 
    o = in; 
    in[ fread(in,1,sizeof(in)-4,stdin)]=0;//set 0 at the end of buffer.
}

int readInt(){ 
   unsigned u = 0, s = 0;
   
   while(*o <= 32)++o; //skip whitespaces... 
   
   while(*o>='0' && *o<='9')u = (u<<3) + (u << 1) + (*o++ - '0');
   
   return static_cast<int>( (u^s) + s) ;
}

//Global
int main() {
  init_in();
  M = readInt();
  N = readInt();
  int len = M*2 -1;
  int a,b,c;
  while(N--){
    a = readInt();
    b = readInt();
    c = readInt();
    arr[a]++;
    arr[a+b]++;
  }
  for(int i = 1; i < len;i++){
    arr[i]+=arr[i-1];
    arr[i-1]++;
  }
  arr[len-1]++;
  for(int r = 0; r < M; r++){
    printf("%d ",arr[len - M - r]);
    for(int c =M ; c < len; c++){
        printf("%d ",arr[c]);
    }
    printf("\n");
  }
}