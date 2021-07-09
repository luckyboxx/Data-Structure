#include "BST.h"
#include <iostream>
using namespace std;

int main() {
	int select, keyvalue;
	BST bst;

	cout << "      < Binary Search Tree >" << endl;
	cout << "============== Menu ==============" << endl;
	cout << "\t[1] Insert" << endl;
	cout << "\t[2] Delete" << endl;
	cout << "\t[3] Search" << endl;
	cout << "\t[4] Inorder" << endl;
	cout << "\t[5] Exit" << endl;
	cout << "==================================" << endl;

	while (1) {
		cout << " ¡à Select :\t ";
		cin >> select;
		switch (select) {
		case 1:
			cout << " - Insert :\t ";
			cin >> keyvalue;
			bst.Insert(keyvalue);
			break;
		case 2:
			cout << " - Delete :\t ";
			cin >> keyvalue;
			if (bst.Delete(keyvalue))
				cout << " - Existence :\t(¡Û)" << endl;
			else cout << " - Existence :\t(¡¿)" << endl;
			break;
		case 3:
			cout << " - Search :\t ";
			cin >> keyvalue;
			bst.Search(keyvalue);
			break;
		case 4:
			bst.Inorder();
			break;
		case 5:
			return 0;
		}
	}
}