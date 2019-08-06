
#include <iostream>
#include <list>
#include <string>
#include "Tree.h"

Node::Node(string v)   //ctor
{
	value = v;
}

void Tree::addRoot(string newval) //create the tree
{
	if (root != NULL)
	{
		deleteAllTree(root);
		delete root;
	}
	root = new Node(newval);

}

Node* Tree::search(Node *p, string val)  //search for a specific value
{
	Node *tmp;
	if (p)
	{
		if(p->value == val)
			return p;
		else
		{
			list<Node *>::iterator it;
			for (it= p->sons.begin(); it!= p->sons.end(); it++)
			{
				if ((*it))
				{
					tmp=search(*it, val);
					if (tmp) return tmp;
				}
			}
		}
	}
	return NULL;
}

void Tree:: addSon(string father, string newval) //add a leaf to the tree
{
	addSon(father, newval, root);
}

void Tree::addSon(string father, string newval, Node* node)  //look for the place that the new leaf has to be
{
	if(node)
		if(node-> value == father)
		{
			Node* n=new Node(newval);
			node->sons.push_back(n);
		}
		else
		{
			list<Node*>:: iterator it;
			
			for (it= node->sons.begin(); it!= node->sons.end(); ++it)
			{
				addSon(father,newval,*it);
			}
		}
}

void Tree:: deleteAllTree(Node *t)  // delete the tree include the root  //עקב בעיתיות בתוכנית שרשומה במודל ובעקבות כך אף אחד מהמרצים לא הצליח את הפונקציה הזו
{                                                                         //אמרו לסטודנטיות להתעלם מפונקציה זו 
	if(t!=NULL)
	{
		if(!(t->sons.empty()))
		{
			list<Node*>:: iterator it;
			for (it= t->sons.begin(); it!= t->sons.end(); it++)
			{
				deleteAllTree(*it);
				
			}
		}
		delete (t);//delete root
		
	}
	
}



void Tree::printAllTree() 
{
	if(root)
		print(root, 0);
}

void Tree:: print(Node *p, int level)  //print all the values from a spacific node
{
	if(p == NULL)
		return;
	if(level == 0)
		cout<< p->value <<endl;
	level += 1;
	list<Node*>:: iterator it;
	for (it= p->sons.begin(); it!= p->sons.end(); it++)
	{
		for(int i=1; i<=level; i++)
			cout<<"  ";
		cout<<(*it)->value <<endl;	
		print(*it,level);
	}
}

void Tree:: searchAndPrint(Node *p, string val)  //print a value with all its fathers
{
	list<Node*>:: iterator it;
	for (it= p->sons.begin(); it!= p->sons.end(); it++)
	{
		Node*tmp = search(*it,val);
		if(tmp->value == val)
		{
			cout<< (*it)->value <<endl;
			searchAndPrint(*it,val);
		}

	}
}

void Tree:: searchAndPrint(string val)
{
	Node*p = search(root,val);
	if(p->value == val)
	{
		cout<< root->value <<endl;
		searchAndPrint(root, val);
	}	
}


void Tree ::printLeaves(Node *t) //print the leaves
{
	list<Node*>:: iterator it;
	for (it= t->sons.begin(); it!= t->sons.end(); it++)
		if((*it)->sons.empty())
			cout<< (*it)->value <<endl;
		else
			printLeaves(*it);	
}