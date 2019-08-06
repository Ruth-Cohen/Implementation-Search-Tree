//========================================
//name: rut goldshtain and Rut Spanyer
//id:315556951 - 316213164
//targil:1
//teacher: Adina Milston
//========================================
#include <iostream>
#include <list>
#include <string>
#include "Tree.h"

int main()
{
	Tree t;
	string val, father;
	char ch;
	do
	{

		cout << "Choose one of the following:" << endl;
		cout << "n: New root:" << endl;
		cout << "s: Put name of area or code of station:" << endl;
		cout << "d: Delete name of area or code of station:" << endl;
		cout << "p: Print all tree" << endl;
		cout << "w: Print the areas of a station" << endl;
		cout << "a: Print stations of area:" << endl;
		cout << "e: exit:" << endl;
		cin >> ch;
		switch (ch)
		{
		case 'n':cout << "enter value of root "; cin >> val; t.addRoot(val); break;
		case 's':cout << "enter value of father and value of son "; cin >> father >> val; t.addSon(father, val); break;
		case 'd':cout << "enter value to delete "; cin >> val; t.deleteSubTree(val); break;
		case 'p':t.printAllTree();  break;
		case 'w':cout << "enter a station "; cin >> val; t.searchAndPrint(val); break;
		case 'a':cout << "enter area to print stations "; cin >> val; t.printLeavesSubtree(val);  break;
		case 'e':cout << "bye "; break;
		default: cout << "error ";  break;
		}
	} while (ch != 'e');
	system("pause");
}