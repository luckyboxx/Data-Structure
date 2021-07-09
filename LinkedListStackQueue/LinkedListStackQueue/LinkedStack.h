#pragma once
#ifndef LinkedStack_h
#define LinkedStack_h
#include "ChainNode.h"
class LinkedStack {
	ChainNode *top;
public:
	LinkedStack(); // ������
	~LinkedStack(); // �ı���
	void Push(const int&);  // ���� �Լ�
	int* Pop();			// ���� �Լ�
	void Print();
};
#endif