#pragma once
#ifndef LinkedQueue_h
#define LinkedQueue_h
#include "ChainNode.h"
class LinkedQueue {
	ChainNode *front;
	ChainNode *rear;
public:
	LinkedQueue(); // 생성자
	~LinkedQueue(); // 파괴자
	void Push(const int&);  // 삽입 함수
	int* Pop();			// 삭제 함수
	void Print();
};
#endif