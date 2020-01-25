#include <iostream>
#include "red_black_tree.h"

rb_node::rb_node(int val)
{
	this->val_ = val;
	this->left_child_ = NULL;
	this->right_child_ = NULL;
}

rb_node::~rb_node() { }

red_black_tree::red_black_tree()
{
	root_ = NULL;
	cnt_ = 0;
}

void red_black_tree::Insert(int val)
{
	rb_node *new_node = new rb_node(val);
	rb_node *parent = this->root_;
	this->cnt_++;
	/*루트 노드가 없다면 == 노드에 원소가 없다
	1. 새로만든 노드가 루트노드가 된다
	2. 루트노드의 부모는 자기 자신이 된다.
	*/
	if (!parent) {
		this->root_ = new_node;
		new_node->color_ = BLACK;
		new_node->parent_ = new_node;
		return ;
	}

	while (true) {
		if (val < parent->val_) {
			if (parent->left_child_) {
				parent = parent->left_child_;
			}
			else {
				parent->left_child_ = new_node;
				new_node->color_ = RED;
				new_node->parent_ = parent;

				_InsertColorCheck(new_node);
				return;
			}
		}
		else {
			if (parent->right_child_) {
				parent = parent->right_child_;
			}
			else {
				parent->right_child_ = new_node;
				new_node->color_ = RED;
				new_node->parent_ =parent;
				_InsertColorCheck(new_node);
				return;
			}
		}
	}
}

void red_black_tree::_InsertColorCheck(rb_node* node)
{
	rb_node *parent = node->parent_, *grand_parent = node->parent_->parent_,*uncle;
	if (parent->color_ == RED) {
		uncle = grand_parent->right_child_ == parent ? grand_parent->left_child_:grand_parent->right_child_;
	}
}