#pragma once
#ifndef BST_H
#define BST_H
#include "BstNode.h"
class BstNode; // 전방선언
class BST {
	friend class BstNode;
private:
	BstNode* root;
public:
	BST();
	~BST();

	BstNode* Search(int data);
	bool Insert(int data);
	int Delete(int data);
	void Inorder();
	void Inorder(BstNode* CurrentNode);
};
#endif // !BST_H