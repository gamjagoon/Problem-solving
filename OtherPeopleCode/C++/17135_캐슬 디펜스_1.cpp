#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans, N, M, D;
bool isIn(int y, int x) {
    return y>= 0 && y < N &&  x>= 0 && x < M;
}

int solve(vector<int> archery, vector<vector<int>> board) {
    int ret = 0;
    
    for (int i = N-1; i >= 0; i--) {
        vector<pair<int,int>> dead;
        
        for (int a_x : archery) {
            bool shoot = false;
            
            for (int d = 0; d < D && !shoot; d++) {
                for (int x = a_x - d; x <= a_x + d && !shoot; x++) {
                    int y = i - (d - (abs(a_x - x)));
                    if (isIn(y,x) && board[y][x] == 1) {
                        shoot = true;
                        dead.emplace_back(y, x);
                    }
                }
            }
        }
        for (auto [y,x] : dead) {
            ret += board[y][x];
            board[y][x] = 0;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> D;
    vector<vector<int>> board(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    for (int t = 0; t < (1<< M); t++) {
        if (__builtin_popcount(t) != 3) continue;
        vector<int> archery;
        for (int i = 0; i < M; i++)
            if (t & (1<<i))
                archery.push_back(i);
        ans = max(ans, solve(archery, board));
    }
    cout << ans;
    return 0;
}