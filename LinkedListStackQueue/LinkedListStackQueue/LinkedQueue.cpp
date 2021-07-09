#include "ChainNode.h"
#include "LinkedQueue.h"
#include <iostream>
using namespace std;

LinkedQueue::LinkedQueue() { front = rear = 0; }
LinkedQueue::~LinkedQueue() {}
// ���� ť ����
void LinkedQueue::Push(const int& e) {
	if (front == 0) front = rear = new ChainNode(e, 0); // ���� ť
	else rear = rear->link = new ChainNode(e, 0); // ��带 �����ϰ� rear�� ������
}

// ���� ť ����
int* LinkedQueue::Pop() {
	// ť�� �ִ� firstNode�� �����ϰ� �� data�� �����͸� ��ȯ
	if (front == 0)	return 0; // ���� ť�̹Ƿ� null�� ��ȯ
	ChainNode* delNode = front;
	int &retvalue = front->data; // �����Ǵ� ���� ratvalue�� ����
	front = front->link; // ���� Node�� ����
	delete delNode; // Node ��ȯ
	return &retvalue;
}

// ���� ť ���
void LinkedQueue::Print() {
	// Node ���� Data�� �ִ��� ������ Ȯ��
	if (front == NULL)	return;	// ������ �����ϰ� ������ �Ʒ� for���� ���� ȭ�鿡 ���
	for (ChainNode* node = front; node != NULL; node = node->link)
		cout << " " << node->data;
	cout << endl;
}