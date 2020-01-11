#include <iostream>
using namespace std;

typedef struct Node{
	int data = 0;
	Node *next = NULL;
}node;

class list
{
private:
	node *head;
public:
	list(){
		head = NULL;
	}

	~list(){
		removeall();
	}

	void removeall()
	{
		node *n = head;
		while(n){
			cout<<"remove"<<n->data<<'\n';
			node * tmp = n;
			n = n->next;
			delete tmp;
		}
		head = NULL;
	}

	void ordered_push(int key){
		node *n = new node;
		n->data = key;
		if(!head){
			cout<<"in head\n";
			head = n;
			return ;
		}
		node *p = head;
		node *q = NULL;
		while(p != NULL && p->data <= key){
			q = p;
			p= p->next;
		}
		//p is NULL
		if(q == NULL){
			n->next = head;
			head = n;
			cout<<head->data<<"in first\n";
			return;
		}
		else if(p == NULL){
			q->next = n;
			cout<<q->data<<"in last\n";
			return;
		}
		else{
			q->next = n;
			n->next = p;
			cout<<q->next->data<<"in middle\n";
			return;
		}
		
		
	}

	node *find_node(int key){
		if(head == NULL)return NULL;
		node *p = head;
		while(p != NULL && p->data < key){
			p = p->next;
		}
		if(p != NULL && p->data == key)return p;
		return NULL;
	}

	void view_list()
	{
		node *p = head;
		while(p){
			cout<<p->data<<' ';
			p = p->next;
		}
		cout<<'\n';
	}

};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	list A;
	int n;cin>>n;
	while(n--){
		int tmp;cin>>tmp;
		cout<<"input "<<tmp<<'\n';
		A.ordered_push(tmp);
	}
	A.view_list();
	node *p = A.find_node(5);
	if(p)cout<<p->data;
	A.removeall();
	A.view_list();
	A.ordered_push(3);
	A.ordered_push(2);
	A.ordered_push(1);
	A.view_list();

}