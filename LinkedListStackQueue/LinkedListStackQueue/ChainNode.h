#pragma once
#ifndef ChainNode_h
#define ChainNode_h
class LinkedStack; // 전방선언
class LinkedQueue; // 전방선언
class ChainNode {
	friend class LinkedStack;
	friend class LinkedQueue;
private:
	int data;
	ChainNode *link;
public:
	ChainNode(int element, ChainNode* next); // 생성자
	~ChainNode(); // 파괴자
};
#endif