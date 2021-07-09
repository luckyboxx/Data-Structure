#include "ChainNode.h"
#include "LinkedStack.h"
#include <iostream>
using namespace std;

// 연결 스택 삽입
LinkedStack::LinkedStack() { top = 0; }
LinkedStack::~LinkedStack() {}
void LinkedStack::Push(const int& e) {
	top = new ChainNode(e, top);
}
// 연결 스택 삭제
int* LinkedStack::Pop() {
	// 스택에서 topNode를 삭제하고 값을 x에 저장한 후에 x의 주소를 반환
	if (top == 0)	return 0;// 빈 스택이면 NULL을 반환
	ChainNode* delNode = top;
	int x = top->data; // topNode의 data 필드를 x에 저장
	top = top->link; // top 위치를 다음 Node로 이동
	delete delNode; // Node 삭제
	return &x;
}

// 연결 스택 출력
void LinkedStack::Print() {
	// Node 내에 Data가 있는지 없는지 확인
	if (top == NULL)	return;	// 없으면 리턴하고 있으면 아래 for문을 통해 화면에 출력
	for (ChainNode* node = top; node != NULL; node = node->link)
		cout << " " << node->data;
	cout << endl;
}