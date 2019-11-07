#include <iostream>
#include <queue>
typedef struct Node {
	int data;
	Node* left = NULL;
	Node* right = NULL;
	Node(int data) {
		this->data = data;
	}
	void add_left(Node* l) {
		this->left = l;
	}
	void add_right(Node* r) {
		this->right = r;
	}
}Node;

Node* A[100];

int main() {
	int a, b;
	for (int i = 0; i < 6; ++i) {
		std::cin >> a >> b;
		Node* p = new Node(a);
		if (p->left == NULL) {
			p->add_left(A[b - 1]);
		}
		else {
			p->add_right(A[b - 1]);
		}
	}
	std::queue<Node *>q;
	q.push(A[0]);
	while (!q.empty()) 
	{
		Node* now = q.front();
		q.pop();
		std::cout << now->data << '\n';
		if(now->left != NULL)
			q.push(now->left);
		if(now->right!= NULL)
			q.push(now->add_right);
	}
	return 0;
}
