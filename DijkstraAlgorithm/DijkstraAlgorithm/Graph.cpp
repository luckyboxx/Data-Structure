#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph(const int vertices) {
	n = vertices;	//���� ��
	length = new int* [n];	//�׷��� ���� ����ġ (��������)
	dist = new int[n];	//�ִܰŸ� �迭 (��������)
	path = new int[n];	//�ִܰŸ� ���� (��������)
	s = new bool[n];	//���õ� ���� (��������)
	for (int i = 0; i < n; i++) {
		length[i] = new int[n];
		for (int j = 0; j < n; j++) {
			if (i == j) length[i][j] = 0;
			else length[i][j] = 9999; // ���Ѵ��� ���
		}
	}
}

Graph::~Graph() { }

void Graph::PrintGraph() {
	cout << " - ����ġ�� ���� �������" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (length[i][j] == 9999)
				cout << "��	";
			else
				cout << length[i][j] << '	';
		}
		cout << endl;
	}
	cout << endl;
}

void Graph::PrintDist() {
	cout << " - ���� ����� �迭 dist�� ��" << endl;
	for (int i = 0; i < n; i++) {
		if (dist[i] != 9999)
			cout << dist[i] << "\t";
		else
			cout << "�� ";
	}
	cout << endl << endl;
}

void Graph::PrintPath(const int v) {
	cout << " - �� ���������� �ִ� ���" << endl;
	for (int i = 0; i < n; i++) {
		if (i != v) {
			cout << "����" << i << ": ";
			if (dist[i] == 9999)
				cout << "��� ����" << endl;
			else {
				int* Stack = new int[n];	//����
				int top = -1;
				Stack[++top] = i;
				while (path[Stack[top]] != v) {	//���ÿ� path �� ���
					Stack[top + 1] = path[Stack[top]];
					top++;
				}
				Stack[++top] = v;
				cout << Stack[top--];
				while (top != -1)	// �������� ���
					cout << " -> " << Stack[top--];
				cout << endl;
				delete[] Stack;
			}
		}
	}
	cout << endl;
}

void Graph::Insertlength(const int v, const int u, const int len) {
	length[v][u] = len;
}

void Graph::ShortestPath(const int v) {	//���ͽ�Ʈ�� �˰���
	for (int i = 0; i < n; i++) {	//�ʱ�ȭ
		dist[i] = length[v][i];
		path[i] = v;
		s[i] = false;
	}
	s[v] = true;
	for (int i = 0; i < n - 2; i++) {	//���������� ���� �ָ� �ִ� ���� ����
		int u = choose(n);	//���� ����
		s[u] = true;	//���� ���� ǥ��
		for (int w = 0; w < n; w++) {	//�ִ� �Ÿ� �� �־��ֱ�
			if (!s[w]) {
				if (dist[u] + length[u][w] < dist[w]) {
					dist[w] = dist[u] + length[u][w];
					path[w] = u;
				}
			}
		}
	}
}

int Graph::choose(const int n) {	//���� ����
	int minpath = -1;	//���� ª�� ����ġ�� ���� ����
	while (s[++minpath]);	//���þȵ� ���� �� ù��° ����
	for (int i = minpath; i < n; i++) {	//���� �ȵ� ������ �ּ� �Ÿ� ã��
		if (!s[i] && dist[i] < dist[minpath])
			minpath = i;
	}
	return minpath;
}