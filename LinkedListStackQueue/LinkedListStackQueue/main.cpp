#include "ChainNode.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include <iostream>
using namespace std;

int main() {
	LinkedStack stack;
	LinkedQueue queue;

	int num, s, q;

	cout << "\t     ---- 메뉴 ---- " << endl;
	cout << " 1. 스택에 삽입   \t2. 큐에 삽입" << endl;
	cout << " 3. 스택에서 삭제\t4. 큐에서 삭제" << endl;
	cout << " 5. 스택 내용 보기\t6. 큐 내용 보기" << endl;
	cout << " 7. 종료" << endl;

	while (true) {
		cout << " >>> ";
		cin >> num;
		switch (num) {
		case 1:
			cin >> s;
			stack.Push(s); // 스택 삽입
			break;
		case 2:
			cin >> q;
			queue.Push(q); // 큐 삽입
			break;
		case 3:
			stack.Pop(); // 스택 삭제
			break;
		case 4:
			queue.Pop(); // 큐 삭제
			break;
		case 5:
			cout << "   스택 (LIFO순) : "; // 스택 출력
			stack.Print();
			cout << endl;
			break;
		case 6:
			cout << "   큐 (FIFO순) : "; // 큐 출력
			queue.Print();
			cout << endl;
			break;
		case 7:
			cout << "해당 프로그램이 종료되었습니다." << endl;
			return 0;
		}
	}
}