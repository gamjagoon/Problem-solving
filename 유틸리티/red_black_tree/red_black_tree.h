#pragma once
#include <iostream>
struct node{
	int data = 0;
	node *left = nullptr;
	node *right = nullptr;
};

class rb_tree
{
	node *head = nullptr;
	node *nill = nullptr;
public:
	rb_tree();

};