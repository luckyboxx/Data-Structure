#include "ChainNode.h"
#include "LinkedStack.h"
#include <iostream>
using namespace std;

// ���� ���� ����
LinkedStack::LinkedStack() { top = 0; }
LinkedStack::~LinkedStack() {}
void LinkedStack::Push(const int& e) {
	top = new ChainNode(e, top);
}
// ���� ���� ����
int* LinkedStack::Pop() {
	// ���ÿ��� topNode�� �����ϰ� ���� x�� ������ �Ŀ� x�� �ּҸ� ��ȯ
	if (top == 0)	return 0;// �� �����̸� NULL�� ��ȯ
	ChainNode* delNode = top;
	int x = top->data; // topNode�� data �ʵ带 x�� ����
	top = top->link; // top ��ġ�� ���� Node�� �̵�
	delete delNode; // Node ����
	return &x;
}

// ���� ���� ���
void LinkedStack::Print() {
	// Node ���� Data�� �ִ��� ������ Ȯ��
	if (top == NULL)	return;	// ������ �����ϰ� ������ �Ʒ� for���� ���� ȭ�鿡 ���
	for (ChainNode* node = top; node != NULL; node = node->link)
		cout << " " << node->data;
	cout << endl;
}