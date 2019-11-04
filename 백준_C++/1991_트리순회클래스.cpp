#include <iostream>
#include <string>

using namespace std;

class tree {
	string data;
	tree* left;
	tree* right;
public:
	tree() {
		data = "";
		left = NULL;
		right = NULL;
	}
	void setdata(char str) {
		this->data = str;
	}
	void setleft(tree* A) {
		this->left = A;
	}
	void setright(tree* A) {
		this->right = A;
	}
	void static preorder(tree* root) { // 전위
		if (root) {
			cout << root->data;
			preorder(root->left);
			preorder(root->right);
		}
	}
	void static inorder(tree* root) { // 중위
		if (root) {
			inorder(root->left);
			cout << root->data;
			inorder(root->right);
		}
	}
	void static postorder(tree* root) { // 후위
		if (root) {
			postorder(root->left);
			postorder(root->right);
			cout << root->data;
		}
	}
};

int main() {
	int n;
	cin >> n;
	tree* a = new tree[n];
	for (int i = 0; i < n; ++i) {
		char data, left, right;
		cin >> data >> left >> right;
		int now = (int)(data - 'A');
		int l = (int)(left - 'A');
		int r = (int)(right - 'A');
		if (data != '.') {
			a[now].setdata(data);
		}
		if (left != '.') {
			a[now].setleft(&a[l]);
		}
		if (right != '.') {
			a[now].setright(&a[r]);
		}
	}
	tree* root = &a[0];
	tree::preorder(root);
	printf("\n");
	tree::inorder(root);
	printf("\n");
	tree::postorder(root);
	printf("\n");
}