#include <iostream>
#include <queue>

using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	queue<int>Card;
	queue<int>G;
	int n = 1;
	while (n <= N) {
		Card.push(n++);
	}
	while (Card.size() != 1) {
		G.push(Card.front());
		Card.pop();
		Card.push(Card.front());
		Card.pop();
	}
	while (!G.empty()) {
		printf("%d ",G.front());
		G.pop();
	}
	printf("%d", Card.front());
	return 0;
}