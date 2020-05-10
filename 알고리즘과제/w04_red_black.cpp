#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ostream>
#include <istream>
#define endl "\n"
constexpr bool RED = true;
constexpr bool BLACK = false;

struct Data
{
	std::string list[5] = { "","","","","" };
	Data() {};
	Data(std::vector<std::string>input) {
		for (int i = 0; i < 5; i++) {
			list[i] = input[i + 1];
		}
	}
	void printdata() {
		std::cout << "    Company: " << list[0] << endl;
		std::cout << "    Address: " << list[1] << endl;
		std::cout << "    Zipcode: " << list[2] << endl;
		std::cout << "    Phones: " << list[3] << endl;
		std::cout << "    Email: " << list[4] << endl;
	}
};

class RBtree {
private:
	struct node {
		Data* data = nullptr;
		std::string key = "";
		node* parent = nullptr;
		node* left = nullptr;
		node* right = nullptr;
		bool  color = RED;
		node() {};
		node(std::vector<std::string>a) {
			key.append(a.front());
			data = new Data(a);
		};
	};
	node* root;
	node* nil;

public:
	int readcnt = 0;
	int writecnt = 0;

	// Create
	RBtree() {
		nil = new node;
		nil->color = BLACK;
		nil->left = nullptr;
		nil->right = nullptr;
		root = nil;
	};
	node* getroot() {
		return root;
	}
	// Search

	node* SearchTreeHelper(node* z,std::string& name) {
		if(z == nil ||name == z->key){
			return z;
		}
		if(name < z->key){
			return SearchTreeHelper(z->left, name);
		}
		return SearchTreeHelper(z->right, name);
	}

	node * SearchTree(std::string& name) {
		return SearchTreeHelper(root,name);
	}

	void left_rotate(node* x) {
		node* y = x->right;
		x->right = y->left;
		if (y->left != nil)
		{
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr)
		{
			this->root = y;
		}
		else if (x == x->parent->left)
		{
			x->parent->left = y;
		}
		else
		{
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}

	void right_rotate(node* x) {
		node* y = x->left;
		x->left = y->right;
		if (y->right != nil)
		{
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr)
		{
			this->root = y;
		}
		else if (x == x->parent->right)
		{
			x->parent->right = y;
		}
		else
		{
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}

	void Insert_fix(node* z)
	{
		node* u;
		while (z->parent->color == RED)
		{
			if (z->parent == z->parent->parent->right)
			{
				u = z->parent->parent->left;
				if (u->color == RED)
				{
					u->color = BLACK;
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				}
				else
				{
					if (z == z->parent->left)
					{
						z = z->parent;
						right_rotate(z);
					}
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					left_rotate(z->parent->parent);
				}
			}
			else
			{
				u = z->parent->parent->right;

				if (u->color == RED)
				{
					u->color = BLACK;
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				}
				else
				{
					if (z == z->parent->right)
					{
						z = z->parent;
						left_rotate(z);
					}
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					right_rotate(z->parent->parent);
				}
			}
			if (z == root)
			{
				break;
			}
		}
		root->color = BLACK;
	}

	// Insert
	void Insert(std::vector<std::string>input) {
		node* z = new node(input);
		z->parent = nullptr;
		z->right = nil; z->left = nil;
		z->color = RED;
#ifdef DEBUG
		std::cout << z->key << ' ';
		for (auto i : z->data->list) {
			std::cout << i << ' ';
		}std::cout << endl;
#endif
		node* y = nullptr;
		node* x = root;
		while (x != nil)
		{
			y = x;
			if (z->data < x->data)
			{
				x = x->left;
			}
			else
			{
				x = x->right;
			}
		}
		z->parent = y;
		if (y == nullptr)
		{
			root = z;
		}
		else if (z->data < y->data)
		{
			y->left = z;
		}
		else
		{
			y->right = z;
		}
		if (z->parent == nullptr)
		{
			z->color = 0;
			return;
		}
		if (z->parent->parent == nullptr)
		{
			return;
		}
		Insert_fix(z);
	}

	void inorderhelper(node* z) {
		if (z != nil && !(z->key.empty()) ) {
			inorderhelper(z->left);
			print(z);
			writecnt++;
			inorderhelper(z->right);
		}
	}
	void inorder() {
		inorderhelper(this->root);
	}

	void print(node* z) {
		std::cout << z->key << endl;
		z->data->printdata();
	}

	void find(std::string name) {
		node* ret = SearchTree(name);
		if (ret == nil || ret == nullptr)std::cout << "Empty\n";
		else {
			print(ret);
		}
	}

	void traceSearch(std::string name) {
		node* s = root;
		while (s != nil) {
			std::cout << s->key << endl;
			if (s->key == name) {
				print(s);
				return;
			}
			else if (name < s->key) {
				s = s->left;
			}
			else {
				s = s->right;
			}
		}
	}

	std::vector<std::string>csv_read(std::ifstream& f, char toc) {
		std::stringstream ss;
		bool flag = false;
		std::vector<std::string>ret;
		while (f.good()) {
			char c = f.get();
			if (!flag && c == '"')
			{
				flag = true;
			}
			else if (flag && c == '"') {
				if (f.peek() == '"') {
					ss << (char)f.get();
				}
				else {
					flag = false;
				}
			}
			else if (!flag && c == toc) {
				ret.push_back(ss.str());
				ss.str("");
			}
			else if (!flag && (c == '\r' || c == '\n')) {
				if (f.peek() == '\n') { f.get(); }
				ret.push_back(ss.str());
				return ret;
			}
			else {
				ss << c;
			}
		}
		ret.push_back(ss.str());
		return ret;
	}
node * minimum(node * node)
  {
    while (node->left != nil)
    {
      node = node->left;
    }
    return node;
  }

  node * maximum(node * node)
  {
    while (node->right != nil)
    {
      node = node->right;
    }
    return node;
  }

  node * successor(node * x)
  {
    if (x->right != nil)
    {
      return minimum(x->right);
    }

    node * y = x->parent;
    while (y != nil && x == y->right)
    {
      x = y;
      y = y->parent;
    }
    return y;
  }
	void deleteFix(node* x)
	{
		node* s;
		while (x != root && x->color == 0)
		{
		if (x == x->parent->left)
		{
			s = x->parent->right;
			if (s->color == 1)
			{
			s->color = 0;
			x->parent->color = 1;
			left_rotate(x->parent);
			s = x->parent->right;
			}

			if (s->left->color == 0 && s->right->color == 0)
			{
			s->color = 1;
			x = x->parent;
			}
			else
			{
			if (s->right->color == 0)
			{
				s->left->color = 0;
				s->color = 1;
				right_rotate(s);
				s = x->parent->right;
			}

			s->color = x->parent->color;
			x->parent->color = 0;
			s->right->color = 0;
			left_rotate(x->parent);
			x = root;
			}
		}
		else
		{
			s = x->parent->left;
			if (s->color == 1)
			{
			s->color = 0;
			x->parent->color = 1;
			right_rotate(x->parent);
			s = x->parent->left;
			}

			if (s->right->color == 0 && s->right->color == 0)
			{
			s->color = 1;
			x = x->parent;
			}
			else
			{
			if (s->left->color == 0)
			{
				s->right->color = 0;
				s->color = 1;
				left_rotate(s);
				s = x->parent->left;
			}

			s->color = x->parent->color;
			x->parent->color = 0;
			s->left->color = 0;
			right_rotate(x->parent);
			x = root;
			}
		}
		}
		x->color = 0;
	}
	void rbTransplant(node* u, node* v)
	{
		if (u->parent == nullptr)
		{
		root = v;
		}
		else if (u == u->parent->left)
		{
		u->parent->left = v;
		}
		else
		{
		u->parent->right = v;
		}
		v->parent = u->parent;
	}
  void deleteNodeHelper(node* n,std::string name)
  {
    node* z = nil;
    node* x = nullptr;
	node* y = nullptr;
    while (n != nil)
    {
      if (n->key == name)
      {
        z = n;
      }

      if (n->key <= name)
      {
        n = n->right;
      }
      else
      {
        n = n->left;
      }
    }

    if (z == nil)
    {
      std::cout << "Key not found in the tree" << endl;
      return;
    }

    y = z;
    int y_original_color = y->color;
    if (z->left == nil)
    {
      x = z->right;
      rbTransplant(z, z->right);
    }
    else if (z->right == nil)
    {
      x = z->left;
      rbTransplant(z, z->left);
    }
    else
    {
      y = minimum(z->right);
      y_original_color = y->color;
      x = y->right;
      if (y->parent == z)
      {
        x->parent = y;
      }
      else
      {
        rbTransplant(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }

      rbTransplant(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
    delete z;
    if (y_original_color == 0)
    {
      deleteFix(x);
    }
  }


	bool read_data(std::string filename) {
		std::ifstream f(filename);
		if (f.fail()) {
			std::cout << "No file \n";
			return false;
		}
		auto tmp = csv_read(f, ',');
		while (f.good()) {
			tmp = csv_read(f, ',');
			if (tmp.size() < 6) {
				for (auto i : tmp)std::cout << i << ' ';
				std::cout << endl;
				std::cout << "file error !\n";
				return false;
			}
			readcnt++;
			Insert(tmp);
		}
		f.close();
		return true;
	}

	void save_all(std::ofstream& a, node* s) {
		if (s != nullptr) {
			save_all(a, s->left);
			a << "\"" << s->key << "\",";
			auto out = s->data->list;
			for (int i = 0; i < 5; i++) {
				a << "\"" << out[i] << "\",";
			}
			a << '\n';
			save_all(a, s->right);
		}
	}

	void save_data(std::string filename) {
		std::ofstream writefile;
		writefile.open(filename);
		node* p = root;
		writefile << "name,company_name,address,zip,phone,email\n";
		save_all(writefile, p);
		writefile.close();
	}
};

std::vector<std::string> input() {
	char buf[512];
	std::cin.getline(buf, 512);
	int s = 0;
	std::vector<std::string>ret;
	while (1) {
		std::string tmp = "";
		while (buf[s] != ' ' && buf[s] != '\0' && buf[s] != '\n') {
			tmp.push_back(buf[s]); s++;
		}
		ret.push_back(tmp);
		if (buf[s] == '\0' || buf[s] == '\n')break;
		s++;
	}
	return ret;
}

int main() {
	RBtree tree = RBtree();
	while (1) {
		std::cout << "$ ";
		auto command = input();
		if (command.size() > 2) {
			std::cout << "Invalid order\n";
			continue;
		}
		else {
			if (command.size() == 1) {
				if (command[0] == "list") {
					if (tree.getroot() == nullptr) {
						std::cout << "Tree is empty\n";
						continue;
					}
					else {
						tree.inorder();
						std::cout<<"list count : "<<tree.writecnt<<endl;
						tree.writecnt = 0;
					}
				}
				else if (command[0] == "exit") {
					return 0;
				}
				else {
					std::cout << "Invalid order\n";
					continue;
				}
			}
			else {
				std::string& order = command[0];
				std::string& argu = command[1];
				if (order == "read") {
					bool flag = tree.read_data(argu);
					if (!flag) {
						std::cout << argu << " read fail!!\n";
						continue;
					}
					std::cout << argu << " read complete !!\n";
					std::cout<<"read count : " << tree.readcnt<<endl;
				}
				else if (order == "save") {
					tree.save_data(argu);
					std::cout << argu << " save complete !!\n";
				}
				else if (order == "find") {
					tree.find(argu);
				}
				else if (order == "trace") {
					tree.traceSearch(argu);
				}
				else if (order == "delete") {

				}
				else {
					std::cout << "Invalid order\n";
					continue;
				}
			}
		}
	}
}