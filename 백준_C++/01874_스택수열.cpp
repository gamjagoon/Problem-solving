#include <iostream>
using namespace std;
int stack[100000]; char res[200000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i, n, k, stkIdx = 0, resIdx = 0, max = 0;
	cin>>n;
	while (n--) {
		cin>>k;
		if (k > max)
			for (i = max; i < k; i++) {
				stack[stkIdx++] = i + 1;
				res[resIdx++] = '+';
			}
		else
			if (stack[stkIdx - 1] != k) {
				cout<<"NO"; return 0;
			}
		stkIdx--;
		res[resIdx++] = '-';
		if (max < k) max = k;
	}
	for (i = 0; i < resIdx; i++) cout<<res[i]<<'\n';
}