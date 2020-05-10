#include <iostream>
  
using namespace std;
  
int T, R, C;
int ans;
char tmp;
char arr[2001][501];
char pw[8];
int code[5][5][5];
  
void init()
{
    code[2][1][1] = 0;
    code[2][2][1] = 1;
    code[1][2][2] = 2;
    code[4][1][1] = 3;
    code[1][3][2] = 4;
    code[2][3][1] = 5;
    code[1][1][4] = 6;
    code[3][1][2] = 7;
    code[2][1][3] = 8;
    code[1][1][2] = 9;
}
  
int convert(char c)
{
    if (c >= 'A')
        return c - 'A' + 10;
    else
        return c - '0';
}
  
int findMin(int a, int b, int c)
{
    int ret;
    ret = a < b ? a : b;
    ret = ret < c ? ret : c;
    return ret;
}
  
bool isValid()
{
    int sum = (pw[1] + pw[3] + pw[5] + pw[7]) * 3
        + pw[0] + pw[2] + pw[4] + pw[6];
  
    if (sum % 10 == 0)
        return true;
    else return false;
}
  
void solve()
{
    ans = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = C - 1; j >= 0; j--)
        {
            if (arr[i][j] == '0')
                continue;
  
            if (arr[i - 1][j] == '0')
            {
                tmp = convert(arr[i][j]);
                int cnt = 0; // 4비트씩
                for (int idx = 0; idx < 8; idx++)
                {
                    int chk[4] = { 0 };
                    for (int k = 0; k <= 3; k++)
                    {
                        while ((tmp & 1) == (k & 1))
                        {
                            chk[k]++;
                            cnt++;
                            tmp >>= 1;
                            if (cnt == 4)
                            {
                                cnt = 0;
                                j--;
                                tmp = convert(arr[i][j]);
                            }
                        }
                    }
                    int _min = findMin(chk[1], chk[2], chk[3]);
                    pw[idx] = code[chk[3] / _min][chk[2] / _min][chk[1] / _min];
                }
                if (isValid())
                    for (int p = 0; p < 8; p++)
                        ans += pw[p];
            }
        }
    }
}
  
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
  
    init();
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> R >> C;
        for (int i = 0; i < R; i++)
            cin >> arr[i];
  
        solve();
        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}
