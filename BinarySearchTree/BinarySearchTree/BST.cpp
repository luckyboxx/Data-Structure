#include "BstNode.h"
#include "BST.h"
#include <iostream>
using namespace std;

BST::BST() { root = NULL; }
BST::~BST() { }

BstNode* BST::Search(int data) {
	BstNode* current = root;	//탐색하기 위한 노드
	while (current != NULL) {
		if (current->key > data) current = current->LeftChild;
		else if (current->key < data) current = current->RightChild;
		else break;
	}
	if (current == NULL)
		cout << " - Existence :\t(×)" << endl;
	else
		cout << " - Existence :\t(○)" << endl;
	return current;
}
bool BST::Insert(int data) {
	BstNode* current = root;	//삽입 위치의 노드
	BstNode* parent = NULL;	//삽입 위치의 부모 노드
	while (current != NULL) {	//위치 찾기
		parent = current;
		if (current->key == data) return false;	//같은 데이터가 있을시에 삽입 실패
		else if (current->key > data) current = current->LeftChild;
		else current = current->RightChild;
	}
	BstNode* InsertNode = new BstNode(data);	//삽입 노드
	if (parent == NULL) root = InsertNode;	//빈 트리일 경우
	else {
		if (parent->key > data) parent->LeftChild = InsertNode;	//부모보다 작은 경우 왼쪽자식에 삽입
		else parent->RightChild = InsertNode;	//부모보다 클 경우 오른쪽 자식에 삽입
	}
	return true;
}
int BST::Delete(int data) {
	BstNode* current = root;	//삭제 위치 노드
	BstNode* parent = NULL;	//삭제 위치 부모 노드
	while (current != NULL && current->key != data) {
		parent = current;
		if (current->key > data) current = current->LeftChild;
		else current = current->RightChild;
	}

	if (current == NULL) return 0;	//데이터가 없는 경우

	if (current->LeftChild == NULL && current->RightChild == NULL) {	//삭제 노드가 단말노드인경우
		if (parent == NULL) root = NULL;	//삭제 노드가 루트 노드일경우
		else if (parent->LeftChild == current) parent->LeftChild = NULL;	//삭제 노드가 왼쪽일경우
		else parent->RightChild = NULL;	//삭제 노드가 오른쪽일경우
	}
	else if (current->LeftChild == NULL || current->RightChild == NULL) {	//삭제 노드가 자식 하나를 가질경우
		BstNode* child;	//삭제 노드의 자식 노드
		if (current->LeftChild != NULL) child = current->LeftChild;		//삭제노드의 자식이 왼쪽에 있을때
		else child = current->RightChild;	//삭제노드의 자식이 오른쪽에 있을때

		if (parent == NULL) root = child;	//루트노드를 삭제할 경우
		else if (parent->LeftChild == current) parent->LeftChild = child;	//왼쪽 자식과 부모 연결
		else parent->RightChild = child;	//오른쪽 자식과 부모 연결
	}
	else {	//삭제노드의 왼쪽 오른쪽 둘다 자식이 있을경우
		BstNode* subcurrent = current->LeftChild;	//왼쪽 서브트리의 최대값을 찾기 위한 노드
		BstNode* subparent = current;	//서브트리의 최대값의 부모 노드
		while (subcurrent->RightChild != NULL) {
			subparent = subcurrent;
			subcurrent = subcurrent->RightChild;
		}
		if (subparent->LeftChild == subcurrent)	//최대값이 기존 부모(parent)의 왼쪽자식(오른쪽 노드로 안내려감)일경우
			subparent->LeftChild = subcurrent->LeftChild;	//기존 부모의 왼쪽과 최대값노드의 왼쪽 자식과 연결
		else	//최대값이 기존 부모의 오른쪽노드로 한번이라도 내려간 경우
			subparent->RightChild = subcurrent->LeftChild;	//최대값 노드의 부모와 최대값 노드의 자식을 연결
		current->key = subcurrent->key;	//삭제 노드의 데이터를 왼쪽 서브트리의 최대값으로 대체
		current = subcurrent;	//대체한 노드를 삭제
	}
	free(current);	//삭제
	return data;
}
void BST::Inorder() {
	cout << " - Inorder:\t";
	Inorder(root);
	cout << endl;
}
void BST::Inorder(BstNode* CurrentNode) {
	if (CurrentNode != NULL) {
		Inorder(CurrentNode->LeftChild);
		cout << CurrentNode->key << " - ";
		Inorder(CurrentNode->RightChild);
	}
}