#include "Graph.h"
#include <iostream>
using namespace std;

int main() {
	int n, m;
	cout << "정점의 수와 간선의 수 > ";
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++) {
		int v, u, l;
		cout << i + 1 << "번째 간선과 가중치 입력 > ";
		cin >> v >> u >> l;
		g.Insertlength(v, u, l);
	}
	int s;
	cout << "시작 정점 입력 > ";
	cin >> s;
	cout << endl;
	g.ShortestPath(s);
	g.PrintGraph();
	g.PrintDist();
	g.PrintPath(s);
}