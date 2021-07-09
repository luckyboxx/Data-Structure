#pragma once
#ifndef BSTNODE_H
#define BSTNODE_H
class BST; // ���漱��
class BstNode {
	friend class BST;
private:
	int key;	// Key��
	BstNode* LeftChild;	// �����ڽ� ������
	BstNode* RightChild;	// �������ڽ� ������
public:
	BstNode(int data);
	~BstNode();
	void SetBstNode(int data, BstNode* left, BstNode* right);
};
#endif // !BSTNODE_H