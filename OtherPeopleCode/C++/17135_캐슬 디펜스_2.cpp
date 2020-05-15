#include <cstdio>

int n, m, l, s;
int a[15][15], b[15][15];

inline void Do(int i, int j) {
  int k, ti, tj;
  for (k = 1; k <= l; k++) for (tj = -k; ++tj < k;) {
    ti = tj < 0 ? k + tj : k - tj;
    if (i >= ti && j + tj >= 0 && j + tj < m && b[i - ti][j + tj]) {
      if (b[i - ti][j + tj] > 0) {
        b[i - ti][j + tj] = -1;
        s++;
      }
      return;
    }
  }
}

int main() {
  int i, j, k, x, y, z, r = 0;
  scanf("%d%d%d", &n, &m, &l);
  for (i = 0; i < n; i++) for (j = 0; j < m; j++) scanf("%d", &a[i][j]);
  for (x = 2; x < m; x++) for (y = 1; y < x; y++) for (z = 0; z < y; z++) {
    s = 0;
    for (i = 0; i < n; i++) for (j = 0; j < m; j++) b[i][j] = a[i][j];
    for (k = n; k; k--) {
      Do(k, x);
      Do(k, y);
      Do(k, z);
      for (i = 0; i < n; i++) for (j = 0; j < m; j++) if (b[i][j] < 0) b[i][j] = 0;
    }
    if (s > r) r = s;
  }
  printf("%d\n", r);
}