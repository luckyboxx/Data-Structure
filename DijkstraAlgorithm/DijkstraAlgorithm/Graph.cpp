#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph(const int vertices) {
	n = vertices;	//정점 수
	length = new int* [n];	//그래프 간선 가중치 (동적생성)
	dist = new int[n];	//최단거리 배열 (동적생성)
	path = new int[n];	//최단거리 정점 (동적생성)
	s = new bool[n];	//선택된 정점 (동적생성)
	for (int i = 0; i < n; i++) {
		length[i] = new int[n];
		for (int j = 0; j < n; j++) {
			if (i == j) length[i][j] = 0;
			else length[i][j] = 9999; // 무한대일 경우
		}
	}
}

Graph::~Graph() { }

void Graph::PrintGraph() {
	cout << " - 가중치를 갖는 인접행렬" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (length[i][j] == 9999)
				cout << "∞	";
			else
				cout << length[i][j] << '	';
		}
		cout << endl;
	}
	cout << endl;
}

void Graph::PrintDist() {
	cout << " - 최종 결과인 배열 dist의 값" << endl;
	for (int i = 0; i < n; i++) {
		if (dist[i] != 9999)
			cout << dist[i] << "\t";
		else
			cout << "∞ ";
	}
	cout << endl << endl;
}

void Graph::PrintPath(const int v) {
	cout << " - 각 정점까지의 최단 경로" << endl;
	for (int i = 0; i < n; i++) {
		if (i != v) {
			cout << "정점" << i << ": ";
			if (dist[i] == 9999)
				cout << "경로 없음" << endl;
			else {
				int* Stack = new int[n];	//스택
				int top = -1;
				Stack[++top] = i;
				while (path[Stack[top]] != v) {	//스택에 path 를 담아
					Stack[top + 1] = path[Stack[top]];
					top++;
				}
				Stack[++top] = v;
				cout << Stack[top--];
				while (top != -1)	// 역순으로 출력
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

void Graph::ShortestPath(const int v) {	//다익스트라 알고리즘
	for (int i = 0; i < n; i++) {	//초기화
		dist[i] = length[v][i];
		path[i] = v;
		s[i] = false;
	}
	s[v] = true;
	for (int i = 0; i < n - 2; i++) {	//시작정점과 가장 멀리 있는 정점 제외
		int u = choose(n);	//선택 정점
		s[u] = true;	//선택 정점 표시
		for (int w = 0; w < n; w++) {	//최단 거리 값 넣어주기
			if (!s[w]) {
				if (dist[u] + length[u][w] < dist[w]) {
					dist[w] = dist[u] + length[u][w];
					path[w] = u;
				}
			}
		}
	}
}

int Graph::choose(const int n) {	//정점 선택
	int minpath = -1;	//제일 짧은 가중치를 가진 정점
	while (s[++minpath]);	//선택안된 정점 중 첫번째 정점
	for (int i = minpath; i < n; i++) {	//선택 안된 정점중 최소 거리 찾기
		if (!s[i] && dist[i] < dist[minpath])
			minpath = i;
	}
	return minpath;
}