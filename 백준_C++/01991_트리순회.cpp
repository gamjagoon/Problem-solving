#include <stdio.h>
#include <ctype.h>
#include <string.h>
int N, k = 0;
char buf[5];
typedef struct node {
	char n = '\0';
	struct node *right = NULL;
	struct node *left = NULL;
}node;

node* list[27];

void read_line() {
	int ch, i = 0;
	while ((ch = getchar()) != '\n') {
		if (ch != ' ') {
			buf[i++] = ch;
		}
	}
	int now = buf[0]-'A', l = buf[1]-'A', r = buf[2]-'A';
	if (buf[0] != '.') {
		list[now]->n = buf[0];
	}
	if (buf[1]!= '.') {
		list[now]->left = list[l];
	}
	if (buf[2]!= '.') {
		list[now]->right = list[r];
	}
}

void primary(node* i) {
	if (i == NULL)return;
	printf("%c", i->n);
	primary(i->left);
	primary(i->right);
}
void midsearch(node *i) {
	if (i == NULL)return;
	midsearch(i->left);
	printf("%c", i->n);
	midsearch(i->right);
}

void back(node* i) {
	if (i == NULL)return;
	back(i->left);
	back(i->right);
	printf("%c", i->n);
}

int main() {
	scanf("%d ", &N);

	for (int i = 0; i <= N; ++i) {
		node *p = new node;
		list[i] = p;
	}
	for (int i = 0; i < N; ++i) {
		memset(buf, '\0', sizeof(buf));
		read_line();
	}
	primary(list[0]);
	printf("\n");
	midsearch(list[0]);
	printf("\n");
	back(list[0]);
	return 0;
}