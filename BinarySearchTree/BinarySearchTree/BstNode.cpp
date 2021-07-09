#include "BstNode.h"
#include <iostream>
BstNode::BstNode(int data) {
	LeftChild = RightChild = NULL;
	key = data;
}
void BstNode::SetBstNode(int data, BstNode* left, BstNode* right) {
	key = data;
	LeftChild = left;
	RightChild = right;
}
BstNode::~BstNode() {
}