#pragma once
#ifndef BSTNODE_H
#define BSTNODE_H
class BST; // 전방선언
class BstNode {
	friend class BST;
private:
	int key;	// Key값
	BstNode* LeftChild;	// 왼쪽자식 포인터
	BstNode* RightChild;	// 오른쪽자식 포인터
public:
	BstNode(int data);
	~BstNode();
	void SetBstNode(int data, BstNode* left, BstNode* right);
};
#endif // !BSTNODE_H