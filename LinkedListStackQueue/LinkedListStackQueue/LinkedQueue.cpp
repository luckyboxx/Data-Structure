#include "ChainNode.h"
#include "LinkedQueue.h"
#include <iostream>
using namespace std;

LinkedQueue::LinkedQueue() { front = rear = 0; }
LinkedQueue::~LinkedQueue() {}
// 연결 큐 삽입
void LinkedQueue::Push(const int& e) {
	if (front == 0) front = rear = new ChainNode(e, 0); // 공백 큐
	else rear = rear->link = new ChainNode(e, 0); // 노드를 삽입하고 rear를 수정함
}

// 연결 큐 삭제
int* LinkedQueue::Pop() {
	// 큐에 있는 firstNode를 제거하고 그 data의 포인터를 반환
	if (front == 0)	return 0; // 공백 큐이므로 null을 반환
	ChainNode* delNode = front;
	int &retvalue = front->data; // 삭제되는 값을 ratvalue에 저장
	front = front->link; // 앞의 Node를 제거
	delete delNode; // Node 반환
	return &retvalue;
}

// 연결 큐 출력
void LinkedQueue::Print() {
	// Node 내에 Data가 있는지 없는지 확인
	if (front == NULL)	return;	// 없으면 리턴하고 있으면 아래 for문을 통해 화면에 출력
	for (ChainNode* node = front; node != NULL; node = node->link)
		cout << " " << node->data;
	cout << endl;
}