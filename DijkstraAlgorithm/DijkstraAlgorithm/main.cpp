#include "Graph.h"
#include <iostream>
using namespace std;

int main() {
	int n, m;
	cout << "������ ���� ������ �� > ";
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++) {
		int v, u, l;
		cout << i + 1 << "��° ������ ����ġ �Է� > ";
		cin >> v >> u >> l;
		g.Insertlength(v, u, l);
	}
	int s;
	cout << "���� ���� �Է� > ";
	cin >> s;
	cout << endl;
	g.ShortestPath(s);
	g.PrintGraph();
	g.PrintDist();
	g.PrintPath(s);
}