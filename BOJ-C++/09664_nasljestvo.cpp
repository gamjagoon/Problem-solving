#include <iostream>
using namespace std;

int main () {
  ios::sync_with_stdio(false);cin.tie(0);
  int N, O;
  cin >> N >> O;
  --N;
  int mx = O / N;
  int min = mx;
  if (mx * N == O)min-=1;
  cout << O + min << " " << O + mx <<"\n";
}