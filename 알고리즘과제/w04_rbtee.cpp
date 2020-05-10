#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ostream>
#include <istream>
using namespace std;

constexpr bool BLACK = false;
constexpr bool RED = true;

struct Address{
	string list[5];
	Address(){};
	Address(vector<string>&&input){
		for(int i = 0 ; i < 5;i++){
		  list[i] = input[i+1];
	  	}
	}
};

struct Node
{
  Address *info;
  string data = "";
  Node *parent;
  Node *left;
  Node *right;
  bool color;
  Node(){
	this->info = nullptr;
	this->data = "";
    this->parent = parent;
    this->left = nullptr;
    this->right = nullptr;
    this->color = BLACK;
  }
  Node(vector<string>&&input)
   {
	   data.append(input[BLACK]);
	   info = new Address(move(input));
		left = nullptr;
		right = nullptr;
		parent = nullptr;
   }
   void diplay(){
	   if(data.length() <= 0){
		   cout<<"empty\n";
		   return;
	   }
	cout<<data<<'\n';
      cout << "\tCompany: " << info->list[0] << '\n';
      cout << "\tAddress: " << info->list[1] << '\n';
      cout << "\tZipcode: " <<info->list[2] << '\n';
      cout << "\tPhones: " << info->list[3] << '\n';
      cout << "\tEmail: " << info->list[4] << '\n';
   }

};

typedef Node *NodePtr;

class RedBlackTree
{
private:
  NodePtr root;
  NodePtr TNULL;

	void Print(NodePtr node){
		node->diplay();
	}
  void initializeNULLNode(NodePtr node, NodePtr parent)
  {
	node->info = nullptr;
    node->data = "";
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = BLACK;
  }

  NodePtr traceHelper(NodePtr node,string key)
  {
    if (node == TNULL)
    {
	  cout<<"Empty\n";
      return node;
    }
	cout<<node->data<<'\n';
	if(key == node->data){
		return node;
	}
    if (key < node->data)
    {
      return traceHelper(node->left, key);
    }
    return traceHelper(node->right, key);
  }

  void inOrderHelper(NodePtr node)
  {
    if (node != TNULL)
    {
      inOrderHelper(node->left);
      node->diplay();
      inOrderHelper(node->right);
    }
  }

  NodePtr searchTreeHelper(NodePtr node, string & key)
  {
    if (node == TNULL || key == node->data)
    {
      return node;
    }

    if (key < node->data)
    {
      return searchTreeHelper(node->left, key);
    }
    return searchTreeHelper(node->right, key);
  }

  void deleteFix(NodePtr x)
  {
    NodePtr s;
    while (x != root && x->color == BLACK)
    {
      if (x == x->parent->left)
      {
        s = x->parent->right;
        if (s->color == RED)
        {
          s->color = BLACK;
          x->parent->color = RED;
          leftRotate(x->parent);
          s = x->parent->right;
        }

        if (s->left->color == BLACK && s->right->color == BLACK)
        {
          s->color = RED;
          x = x->parent;
        }
        else
        {
          if (s->right->color == BLACK)
          {
            s->left->color = BLACK;
            s->color = RED;
            rightRotate(s);
            s = x->parent->right;
          }

          s->color = x->parent->color;
          x->parent->color = BLACK;
          s->right->color = BLACK;
          leftRotate(x->parent);
          x = root;
        }
      }
      else
      {
        s = x->parent->left;
        if (s->color == RED)
        {
          s->color = BLACK;
          x->parent->color = RED;
          rightRotate(x->parent);
          s = x->parent->left;
        }

        if (s->right->color == BLACK && s->right->color == BLACK)
        {
          s->color = RED;
          x = x->parent;
        }
        else
        {
          if (s->left->color == BLACK)
          {
            s->right->color = BLACK;
            s->color = RED;
            leftRotate(s);
            s = x->parent->left;
          }

          s->color = x->parent->color;
          x->parent->color = BLACK;
          s->left->color = BLACK;
          rightRotate(x->parent);
          x = root;
        }
      }
    }
    x->color = BLACK;
  }

  void rbTransplant(NodePtr u, NodePtr v)
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

  void deleteNodeHelper(NodePtr node, string& key)
  {
    NodePtr z = TNULL;
    NodePtr x, y;
    while (node != TNULL)
    {
      if (node->data == key)
      {
        z = node;
      }

      if (node->data <= key)
      {
        node = node->right;
      }
      else
      {
        node = node->left;
      }
    }

    if (z == TNULL)
    {
      cout << "Key not found in the tree" << endl;
      return;
    }

    y = z;
    bool y_original_color = y->color;
    if (z->left == TNULL)
    {
      x = z->right;
      rbTransplant(z, z->right);
    }
    else if (z->right == TNULL)
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
	cout<<z->data<<" deleted!!\n";
    delete z;
    if (y_original_color == BLACK)
    {
      deleteFix(x);
    }
  }

  void insertFix(NodePtr k)
  {
    NodePtr u;
    while (k->parent->color == RED)
    {
      if (k->parent == k->parent->parent->right)
      {
        u = k->parent->parent->left;
        if (u->color == RED)
        {
          u->color = BLACK;
          k->parent->color = BLACK;
          k->parent->parent->color = RED;
          k = k->parent->parent;
        }
        else
        {
          if (k == k->parent->left)
          {
            k = k->parent;
            rightRotate(k);
          }
          k->parent->color = BLACK;
          k->parent->parent->color = RED;
          leftRotate(k->parent->parent);
        }
      }
      else
      {
        u = k->parent->parent->right;

        if (u->color == RED)
        {
          u->color = BLACK;
          k->parent->color = BLACK;
          k->parent->parent->color = RED;
          k = k->parent->parent;
        }
        else
        {
          if (k == k->parent->right)
          {
            k = k->parent;
            leftRotate(k);
          }
          k->parent->color = BLACK;
          k->parent->parent->color = RED;
          rightRotate(k->parent->parent);
        }
      }
      if (k == root)
      {
        break;
      }
    }
    root->color = BLACK;
  }

public:
  RedBlackTree()
  {
    TNULL = new Node;
    TNULL->color = BLACK;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
  }

  NodePtr trace(string name)
  {
    return traceHelper(this->root, name);
  }

  void inorder()
  {
    inOrderHelper(this->root);
  }

  NodePtr searchTree(string& k)
  {
    return searchTreeHelper(this->root, k);
  }

  NodePtr minimum(NodePtr node)
  {
    while (node->left != TNULL)
    {
      node = node->left;
    }
    return node;
  }

  NodePtr maximum(NodePtr node)
  {
    while (node->right != TNULL)
    {
      node = node->right;
    }
    return node;
  }

  NodePtr successor(NodePtr x)
  {
    if (x->right != TNULL)
    {
      return minimum(x->right);
    }

    NodePtr y = x->parent;
    while (y != TNULL && x == y->right)
    {
      x = y;
      y = y->parent;
    }
    return y;
  }

  NodePtr predecessor(NodePtr x)
  {
    if (x->left != TNULL)
    {
      return maximum(x->left);
    }

    NodePtr y = x->parent;
    while (y != TNULL && x == y->left)
    {
      x = y;
      y = y->parent;
    }

    return y;
  }

  void leftRotate(NodePtr x)
  {
    NodePtr y = x->right;
    x->right = y->left;
    if (y->left != TNULL)
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

  void rightRotate(NodePtr x)
  {
    NodePtr y = x->left;
    x->left = y->right;
    if (y->right != TNULL)
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

  void insert(vector<string>&&input)
  {
    NodePtr node = new Node(move(input));
    node->parent = nullptr;
    node->left = TNULL;
    node->right = TNULL;
    node->color = RED;

    NodePtr y = nullptr;
    NodePtr x = this->root;

    while (x != TNULL)
    {
      y = x;
      if (node->data < x->data)
      {
        x = x->left;
      }
      else
      {
        x = x->right;
      }
    }

    node->parent = y;
    if (y == nullptr)
    {
      root = node;
    }
    else if (node->data < y->data)
    {
      y->left = node;
    }
    else
    {
      y->right = node;
    }

    if (node->parent == nullptr)
    {
      node->color = BLACK;
      return;
    }

    if (node->parent->parent == nullptr)
    {
      return;
    }

    insertFix(node);
  }

  NodePtr getRoot()
  {
    return this->root;
  }

  void deleteNode(string & data)
  {
    deleteNodeHelper(this->root, data);
  }

void save_all(ofstream &f,Node *node){
    if (node != nullptr){
      
    save_all(f,node->left);
    f<<"\""<<node->data<<"\",";
    f<<"\""<<node->info->list[0]<<"\",";
    f<<"\""<<node->info->list[1]<<"\",";
    f<<"\""<<node->info->list[2]<<"\",";
    f<<"\""<<node->info->list[3]<<"\",";
    f<<"\""<<node->info->list[4]<<"\""<<endl;
    
    save_all(f,node->right);
    }
}
  void save(string f){
    ofstream fout(f);
    
    fout<<"name,";
    fout<<"company,";
    fout<<"address,";
    fout<<"zip,";
    fout<<"phone,";
    fout<<"email"<<endl;
    save_all(fout,root);
    fout.close();
 }
};

vector<string> csv_read_row(istream& in, char delimiter);

int main(int argc, char* argv[])

{

   //ifstream은 파일을 읽게 해주는 함수로써 ifstream (파일명 or 경로)
   RedBlackTree root = RedBlackTree();
   
   while (true) {
      cout << "$ ";
      string temp;
      getline(cin, temp);
        if(temp==""){
            continue;
        }
      stringstream commands;
      commands.str(temp);
      string token;
      vector<string> command;
      while (commands >> token) {
         command.push_back(token);
      }
      if (command[0] == "list") {
         if (command.size() != 1) {
            cout << "command error\n";
         }
         else {
            root.inorder();
         }
      }
        else if (command[0] == "read") {
         if (command.size() != 2) {
            cout << "command error\n";
         }
         else {    
            ifstream in(command[1]);
                if (in.fail()) return (cout << "Not found File" << endl) && 0;
                vector<string> input = csv_read_row(in, ',');
                while (in.good())
                {
                    vector<string> input = csv_read_row(in, ',');
                    if (input.size() != 6) {
                        cout << "file error\n";
                        return 0;
                    }
                    root.insert(move(input));
                }
            in.close();
         }
      }
      else if (command[0] == "exit") {
         if (command.size() != 1) {
            cout << "command error\n";
         }
         else {
            break;
         }

      }
      else if (command[0] == "delete") {
         if (command.size() != 2) {
            cout << "command error\n";
         }
         else {
            root.deleteNode(command[1]);
         }
      }
      else if (command[0] == "find") {
         if (command.size() != 2) {
            cout << "command error\n";
         }
         else {
            root.searchTree(command[1])->diplay();
         }

      }
        else if(command[0]=="trace"){
            if (command.size() != 2) {
            cout << "command error\n";

         }
         else {
            root.trace(command[1])->diplay();
         }
        }
        else if(command[0]=="save"){
            if (command.size() != 2) {
            cout << "command error\n";

         }
         else {
            root.save(command[1]);
         }
        }
        
      commands.clear();

   }


   return 0;
}



vector<string> csv_read_row(istream& in, char delimiter)
{
   stringstream ss;
   bool inquotes = false;
   vector<string> row;//relying on RVO
   while (in.good())
   {
      char c = in.get();
      if (!inquotes && c == '"') //beginquotechar
      {
         inquotes = true;
      }
      else if (inquotes && c == '"') //quotechar
      {
         if (in.peek() == '"')//2 consecutive quotes resolve to 1
         {
            ss << (char)in.get();
         }
         else //endquotechar
         {
            inquotes = false;
         }
      }
      else if (!inquotes && c == delimiter) //end of field
      {
         row.push_back(ss.str());
         ss.str("");
      }
      else if (!inquotes && (c == '\r' || c == '\n'))
      {
         if (in.peek() == '\n') { in.get(); }
         row.push_back(ss.str());
         return row;
      }
      else
      {
         ss << c;
      }
   }
    row.push_back(ss.str());

   return row;
}