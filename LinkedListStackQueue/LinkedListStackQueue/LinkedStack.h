#pragma once
#ifndef LinkedStack_h
#define LinkedStack_h
#include "ChainNode.h"
class LinkedStack {
	ChainNode *top;
public:
	LinkedStack(); // 생성자
	~LinkedStack(); // 파괴자
	void Push(const int&);  // 삽입 함수
	int* Pop();			// 삭제 함수
	void Print();
};
#endif