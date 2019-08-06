#include <iostream>
#include <list>
#include <string>

using namespace std;
class Node
{
	list<Node *> sons;
	string value;
public:
	Node(string v);
	friend class Tree;
};

class Tree
{
	Node *root;
	void addSon(string father, string newval, Node* root);
	
public:
	Tree() { root = NULL; }
	~Tree() {
		deleteAllTree(root);
	}
	
	void addRoot(string newval);
	void addSon(string father, string newval);
	void searchAndPrint(string val);
	void searchAndPrintArea(string val){searchAndPrint (root, val);}
	void printAllTree();
	void printAllLeaves() {printLeaves (root);}
	void printLeavesSubtree(string val) { Node *t = search(root, val); if (t) printLeaves(t); }
	void deleteSubTree(string val) { Node *t = search(root, val); if (t) deleteAllTree(t); }
	
private:
	void deleteAllTree(Node *t);
	Node* search(Node *p, string val);
	void searchAndPrint(Node *p, string val);
	void print(Node *p, int level);
	void printLeaves(Node *t);

};