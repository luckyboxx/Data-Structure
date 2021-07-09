#include "ChainNode.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include <iostream>
using namespace std;

int main() {
	LinkedStack stack;
	LinkedQueue queue;

	int num, s, q;

	cout << "\t     ---- �޴� ---- " << endl;
	cout << " 1. ���ÿ� ����   \t2. ť�� ����" << endl;
	cout << " 3. ���ÿ��� ����\t4. ť���� ����" << endl;
	cout << " 5. ���� ���� ����\t6. ť ���� ����" << endl;
	cout << " 7. ����" << endl;

	while (true) {
		cout << " >>> ";
		cin >> num;
		switch (num) {
		case 1:
			cin >> s;
			stack.Push(s); // ���� ����
			break;
		case 2:
			cin >> q;
			queue.Push(q); // ť ����
			break;
		case 3:
			stack.Pop(); // ���� ����
			break;
		case 4:
			queue.Pop(); // ť ����
			break;
		case 5:
			cout << "   ���� (LIFO��) : "; // ���� ���
			stack.Print();
			cout << endl;
			break;
		case 6:
			cout << "   ť (FIFO��) : "; // ť ���
			queue.Print();
			cout << endl;
			break;
		case 7:
			cout << "�ش� ���α׷��� ����Ǿ����ϴ�." << endl;
			return 0;
		}
	}
}