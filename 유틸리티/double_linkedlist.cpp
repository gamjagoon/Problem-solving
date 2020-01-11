#include <iostream>
using namespace std;

class doublelist{
public:
	typedef struct Node{
		int data;
		Node *pre,*next;
	}node;
	doublelist()
	{
		_init();
	}
	void _init(){
		head = new node;
		tail = new node;
		head->next = tail;
		head->pre = head;
		tail->next = tail;
		tail->pre = head;
		m_cout = 0;
	}
	void* InsertBefor(void* pos,const int newelem)
	{
		if(pos == (void*)head || pos == 0)return 0;
		node *n = (node*)pos;
		node *nn = new node;
		nn->data = newelem;
		n -> pre ->next = nn;
		nn->pre = n->pre;
		nn->next = n;
		n->pre = nn;
		m_cout++;
		return nn;
	}
	void* InsertNext(void* pos,const int newelem)
	{
		if(pos == (void*)head || pos == 0)return 0;
		node *n = (node*)pos;
		node *nn = new node;
		nn->data = newelem;
		n -> next ->pre = nn;
		nn->next = n->next;
		nn->pre = n;
		n->next = nn;
		m_cout++;
		return nn;
	}

private:
	node *head,*tail;
	int m_cout;
};