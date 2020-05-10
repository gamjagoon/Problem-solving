#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include <vector>
#include <string>
#include <istream>

using namespace std;

class Node
{
public:
   string list[6];
   Node* left;
   Node* right;
   Node* parrent;
   Node(vector<string>&&input)
   {
      for(int i = 0 ; i < 6;i++){
		  list[i] = input[i];
	  }
      left = nullptr;
      right = nullptr;
      parrent = nullptr;
   }

   void Print()
   {
      cout << list[0]<< '\n';
      cout << "\tCompany: " << list[1] << '\n';
      cout << "\tAddress: " << list[2] << '\n';
      cout << "\tZipcode: " <<list[3] << '\n';
      cout << "\tPhones: " << list[4] << '\n';
      cout << "\tEmail: " << list[5] << '\n';
   }
};

class Bstree
{
public:
   Bstree() : root(nullptr) {};
   ~Bstree() {};
   void Insert(vector<string> value);
   bool Search(string name);
   void RemoveNode(string name);
   void Display();
    bool trace(string name);
    void save(string f);
private:
   Node* root;

   void Inorder(Node* current)
   {
      if (current != nullptr)
      {
         Inorder(current->left);
         current->Print();
         Inorder(current->right);
      }
   }
   Node* SearchMaxNode(Node* node)
   {
      if (node == NULL)
         return NULL;
      while (node->right != NULL)
      {
         node = node->right;
      }
      return node;
   }
    void save_all(ofstream &f,Node *node);
   Node* Removehelper(Node* node, string _vaule);
};

Node* Bstree::Removehelper(Node* node, string name)
{
   if (node == nullptr)
      return node;
    
   else if (node->list[0] > name)
      node->left = Removehelper(node->left, name);
   else if (node->list[0] < name)
      node->right = Removehelper(node->right, name);
   else
   {
      Node* ptr = node;
      if (node->right == nullptr && node->left == nullptr)
      {
         delete node;
         node = nullptr;
      } 
      else if (node->right == nullptr)
      {
         node = node->left;
         node->parrent = ptr->parrent;
         delete ptr;
      }
      else if (node->left == nullptr)
      {
         node = node->right;
         node->parrent = ptr->parrent;
         delete ptr;
      } //자식이 두개일떄 :: 왼쪽 노드중 가장큰값 찾아 부모노드로 바꾸기
      else
      {
         ptr = SearchMaxNode(node->left);
         node->list[0] = ptr->list[0];
         node->list[1] = ptr->list[1];
         node->list[2] = ptr->list[2];
         node->list[3] = ptr->list[3];
         node->list[4] = ptr->list[4];
         node->list[5] = ptr->list[5];
         node->left = Removehelper(node->left, ptr->list[0]);
      }
   }
   return node;
}
void Bstree::RemoveNode(string name)
{
   Node* ptr = root;
   ptr=Removehelper(ptr, name);
}

void Bstree::Display() { Inorder(root); }
void Bstree::save_all(ofstream &f,Node *node){
    if (node != nullptr){
      
    save_all(f,node->left);
    f<<"\""<<node->list[0]<<"\",";
    f<<"\""<<node->list[1]<<"\",";
    f<<"\""<<node->list[2]<<"\",";
    f<<"\""<<node->list[3]<<"\",";
    f<<"\""<<node->list[4]<<"\",";
    f<<"\""<<node->list[5]<<"\""<<endl;
    
    save_all(f,node->right);
    }
}
void Bstree::save(string f){
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
bool Bstree::trace(string name){
       Node* ptr = root;
   while (ptr != nullptr)
   {
        cout<<ptr->list[0]<<'\n';
      if (ptr->list[0] == name)
      {
         ptr->Print();
         return true;
      }
      else if (ptr->list[0]> name)
         ptr = ptr->left;
      else
         ptr = ptr->right;
        
   }
   cout << name << " not found\n";
   return false;
}

bool Bstree::Search(string name)
{
   Node* ptr = root;
   while (ptr != nullptr)
   {
      if (ptr->list[0] == name)
      {
         ptr->Print();
         return true;
      }
      else if (ptr->list[0] > name)
         ptr = ptr->left;
      else
         ptr = ptr->right;
   }
   cout << name << " not found\n";
   return false;
}


void Bstree::Insert(vector<string> input)
{
   Node* node = new Node(move(input));
   Node* tmpRoot = nullptr;
   if (root == nullptr)
      root = node;
   else
   {
      Node* ptr = root;
      while (ptr != nullptr)
      {
         tmpRoot = ptr;
         if (node->list[0] < ptr->list[0])
         {
            ptr = ptr->left;
         }
         else
         {
            ptr = ptr->right;
         }
      } //넣을 위치에 대입
      if (node->list[0] < tmpRoot->list[0])
      {
         tmpRoot->left = node;
         node->parrent = tmpRoot;
      }
      else
      {
         tmpRoot->right = node;
         node->parrent = tmpRoot;
      }
   }
}

vector<string> csv_read_row(istream& in, char delimiter);

int main(int argc, char* argv[])

{

   //ifstream은 파일을 읽게 해주는 함수로써 ifstream (파일명 or 경로)
   Bstree root = Bstree();
   
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
            root.Display();
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
                    root.Insert(input);
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
            root.RemoveNode(command[1]);
         }
      }
      else if (command[0] == "find") {
         if (command.size() != 2) {
            cout << "command error\n";
         }
         else {
            root.Search(command[1]);
         }

      }
        else if(command[0]=="trace"){
            if (command.size() != 2) {
            cout << "command error\n";

         }
         else {
            root.trace(command[1]);
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