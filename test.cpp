#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
 
int N, person[11], Min = 2e9;
vector<int> v[11];
 
bool chk(vector<int> vc)
{
    bool visit[11]; memset(visit, false, sizeof(visit));
    visit[vc[0]] = true;
    queue<int> q;
    q.push(vc[0]);
    while (!q.empty())
    {
        int qs = q.size();
        while (qs--)
        {
            int here = q.front();
            q.pop();
            for (auto next : v[here])
                for(auto i : vc)
                    if (!visit[next] && i == next)
                    {
                        visit[next] = true;
                        q.push(next);
                        break;
                    }        
        }
    }
 
    for (auto i : vc) if (!visit[i]) return false;
    return true;
}
 
void bt(vector<int> g, int idx)
{
    if (g.size() == N) return;
 
    if (!g.empty())
    {
        vector<int> temp;
        bool visit[11]; memset(visit, false, sizeof(visit));
        int gsum = 0, tempsume = 0;
 
        for (auto i : g) { visit[i] = true; gsum += person[i]; }
        for (int i = 1; i <= N; i++)
            if (!visit[i]) {
                temp.push_back(i);
                tempsume += person[i];
            }
        if (chk(g) && chk(temp)) Min = min(Min, abs(gsum - tempsume));    
    }
 
    for (int i = idx; i <= N; i++) {
        g.push_back(i);
        bt(g, i + 1);
        g.pop_back();
    }
}
 
int main(void)
{    
    int adj, input;
 
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &person[i]);
 
    for (int i = 1; i <= N; i++) {
        scanf("%d", &adj);
        for (int j = 0; j < adj; j++) {
            scanf("%d", &input);
            v[i].push_back(input);
            v[input].push_back(i);
        }
    }
 
    vector<int> g; bt(g, 1);
    printf("%d\n", Min == 2e9 ? -1 : Min);
 
    return 0;
}