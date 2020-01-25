#pragma once
constexpr auto RED = true;
constexpr auto BLACK = false;

class rb_node
{
private:
	int val_;
	bool color_;
	rb_node *parent_,*left_child_,*right_child_;
	friend class red_black_tree;
public:
	rb_node(int val);
	~rb_node();
};

class red_black_tree
{
private:
	rb_node *root_;
	int cnt_;
	void _Delete(rb_node *node);
	void _InsertColorCheck(rb_node *node);
	void R_right(rb_node *node);
	void R_left(rb_node *node);
public:
	red_black_tree();
	~red_black_tree();
	void Insert(int val);
	void Delete(int val);
	void Print();
};

