#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
typedef struct Game {
	int data;
	int strike;
	int ball;
}Game;

int test_case,num, st, ball, result = 0;
vector<Game>V;
vector <int>can;
// find return true not find return false
bool findresult(int now) {
	int n1, n2, n3;
	n3 = now;
	n1 = n3 % 10;
	n3 /= 10;
	n2 = n3 % 10;
	n3 /= 10;
	int c1, c2;
	for (int i = 0; i < V.size(); ++i) {
		int ns = 0, nb = 0;
		int c3 = V[i].data;
		int st = V[i].strike;
		int ba = V[i].ball;
		c1 = c3% 10;
		c3 /= 10;
		c2 = c3 % 10;
		c3 /= 10;
		if (c1 == n1) {
			ns++;
		}
		else if (c1 == n2) {
			nb++;
		}
		else if (c1 == n3) {
			nb++;
		}
		if (c2 == n2) {
				ns++;
		}
		else if ( c2 == n1) {
			nb++;
		}
		else if (c2 == n3) {
			nb++;
		}
		if (c3 == n3) {
			ns++;
		}
		else if (c3 == n1) {
			nb++;
		}
		else if (c3 == n3) {
			nb++;
		}
		if (st != ns || ba != nb) {
			return  false;
		}
	}
	return true;
}


int main() {
	scanf("%d", &test_case);
	Game g;
	for (int i = 123; i < 988; ++i) {
		int tmp = i;
		int t1, t2;
		t1 = tmp % 10;
		if (t1 == 0)continue;
		tmp /= 10;
		t2 = tmp% 10;
		if (t2 == 0 || t1 == t2 )continue;
		tmp/= 10;
		if (tmp == 0 || t1 == tmp|| t2 == tmp)continue;
		else {
			can.push_back(i);
		}
	}
	while (test_case--)
	{
		scanf("%d %d %d", &num,&st,&ball);
		g.data = num;
		g.strike = st;
		g.ball = ball;
		V.push_back(g);
	}
	for (int i = 0; i < can.size(); ++i) {
		int data = can[i];
		if (findresult(data)) {
			result++;
			continue;
		}
		else {
			continue;
		}
	}
	printf("%d", result);
}