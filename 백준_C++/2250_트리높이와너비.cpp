#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


typedef struct node {
	int left = -1;
	int right = -1;
	int parent = -1;
}node ;
node Tree[10001];
vector<pair<int, int>>arr;
int max_level = 1, max_len = 1, result_level = 1;
int root = 1;
void init();
void make_arr(int now_node,int level,bool dir);
void calc_max();

void find_root() {
	while (Tree[root].parent != -1) {
		root = Tree[root].parent;
	}
}

int main()
{
	init();
	find_root();
	make_arr(root,1,true);
	calc_max();
	printf("%d %d", result_level, max_len);
	return 0;
}


void init() {
	int input_case;
	scanf("%d\n", &input_case);
	int name, left, right;
	while (input_case--) {
		scanf("%d %d %d", &name, &left, &right);
		if (left != -1) {
			Tree[name].left = left;
			Tree[left].parent = name;
		}
		if (right != -1)
		{
			Tree[name].right = right;
			Tree[right].parent = name;
		}
	}
}


void make_arr(int now_node,int level,bool dir )
{
	//리프 노드일경우

	if(Tree[now_node].left != -1 ) {
		make_arr(Tree[now_node].left, level + 1,true);
	}
	if (Tree[now_node].left == -1 ) {
		arr.push_back({ now_node,level });
		if (dir) {
			Tree[Tree[now_node].parent].left = -1;
		}
		else {
			Tree[Tree[now_node].parent].right = -1;
		}
		max_level = level > max_level ? level : max_level;
	}
	if (Tree[now_node].right != -1 ) {
		make_arr(Tree[now_node].right, level + 1,false);
	}
	else return;
}

void calc_max()
{
	int end = arr.size() - 1;
	int now_level = 2;
	while(now_level <= max_level){
		int i = 0;
		while (arr[i].second != now_level) i++;
		int j = end;
		while (arr[j].second != now_level)j--;
		int tmp_level = j - i + 1;
		if (tmp_level > max_len) {
			result_level = now_level;
			max_len = tmp_level;
		}
		now_level++;
	}
}
