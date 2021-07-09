#include "BstNode.h"
#include "BST.h"
#include <iostream>
using namespace std;

BST::BST() { root = NULL; }
BST::~BST() { }

BstNode* BST::Search(int data) {
	BstNode* current = root;	//Ž���ϱ� ���� ���
	while (current != NULL) {
		if (current->key > data) current = current->LeftChild;
		else if (current->key < data) current = current->RightChild;
		else break;
	}
	if (current == NULL)
		cout << " - Existence :\t(��)" << endl;
	else
		cout << " - Existence :\t(��)" << endl;
	return current;
}
bool BST::Insert(int data) {
	BstNode* current = root;	//���� ��ġ�� ���
	BstNode* parent = NULL;	//���� ��ġ�� �θ� ���
	while (current != NULL) {	//��ġ ã��
		parent = current;
		if (current->key == data) return false;	//���� �����Ͱ� �����ÿ� ���� ����
		else if (current->key > data) current = current->LeftChild;
		else current = current->RightChild;
	}
	BstNode* InsertNode = new BstNode(data);	//���� ���
	if (parent == NULL) root = InsertNode;	//�� Ʈ���� ���
	else {
		if (parent->key > data) parent->LeftChild = InsertNode;	//�θ𺸴� ���� ��� �����ڽĿ� ����
		else parent->RightChild = InsertNode;	//�θ𺸴� Ŭ ��� ������ �ڽĿ� ����
	}
	return true;
}
int BST::Delete(int data) {
	BstNode* current = root;	//���� ��ġ ���
	BstNode* parent = NULL;	//���� ��ġ �θ� ���
	while (current != NULL && current->key != data) {
		parent = current;
		if (current->key > data) current = current->LeftChild;
		else current = current->RightChild;
	}

	if (current == NULL) return 0;	//�����Ͱ� ���� ���

	if (current->LeftChild == NULL && current->RightChild == NULL) {	//���� ��尡 �ܸ�����ΰ��
		if (parent == NULL) root = NULL;	//���� ��尡 ��Ʈ ����ϰ��
		else if (parent->LeftChild == current) parent->LeftChild = NULL;	//���� ��尡 �����ϰ��
		else parent->RightChild = NULL;	//���� ��尡 �������ϰ��
	}
	else if (current->LeftChild == NULL || current->RightChild == NULL) {	//���� ��尡 �ڽ� �ϳ��� �������
		BstNode* child;	//���� ����� �ڽ� ���
		if (current->LeftChild != NULL) child = current->LeftChild;		//��������� �ڽ��� ���ʿ� ������
		else child = current->RightChild;	//��������� �ڽ��� �����ʿ� ������

		if (parent == NULL) root = child;	//��Ʈ��带 ������ ���
		else if (parent->LeftChild == current) parent->LeftChild = child;	//���� �ڽİ� �θ� ����
		else parent->RightChild = child;	//������ �ڽİ� �θ� ����
	}
	else {	//��������� ���� ������ �Ѵ� �ڽ��� �������
		BstNode* subcurrent = current->LeftChild;	//���� ����Ʈ���� �ִ밪�� ã�� ���� ���
		BstNode* subparent = current;	//����Ʈ���� �ִ밪�� �θ� ���
		while (subcurrent->RightChild != NULL) {
			subparent = subcurrent;
			subcurrent = subcurrent->RightChild;
		}
		if (subparent->LeftChild == subcurrent)	//�ִ밪�� ���� �θ�(parent)�� �����ڽ�(������ ���� �ȳ�����)�ϰ��
			subparent->LeftChild = subcurrent->LeftChild;	//���� �θ��� ���ʰ� �ִ밪����� ���� �ڽİ� ����
		else	//�ִ밪�� ���� �θ��� �����ʳ��� �ѹ��̶� ������ ���
			subparent->RightChild = subcurrent->LeftChild;	//�ִ밪 ����� �θ�� �ִ밪 ����� �ڽ��� ����
		current->key = subcurrent->key;	//���� ����� �����͸� ���� ����Ʈ���� �ִ밪���� ��ü
		current = subcurrent;	//��ü�� ��带 ����
	}
	free(current);	//����
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