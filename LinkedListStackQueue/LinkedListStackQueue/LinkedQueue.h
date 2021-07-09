#pragma once
#ifndef LinkedQueue_h
#define LinkedQueue_h
#include "ChainNode.h"
class LinkedQueue {
	ChainNode *front;
	ChainNode *rear;
public:
	LinkedQueue(); // ������
	~LinkedQueue(); // �ı���
	void Push(const int&);  // ���� �Լ�
	int* Pop();			// ���� �Լ�
	void Print();
};
#endif