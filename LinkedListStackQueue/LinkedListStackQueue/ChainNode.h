#pragma once
#ifndef ChainNode_h
#define ChainNode_h
class LinkedStack; // ���漱��
class LinkedQueue; // ���漱��
class ChainNode {
	friend class LinkedStack;
	friend class LinkedQueue;
private:
	int data;
	ChainNode *link;
public:
	ChainNode(int element, ChainNode* next); // ������
	~ChainNode(); // �ı���
};
#endif