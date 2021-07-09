#pragma once
#ifndef GRAPH_H
#define GRAPH_H

class Graph {
private:
	int** length;	// ������ �迭
	int* dist;		// ������ �迭
	int* path;		// ������ �迭
	bool* s;		// ������ �迭
	int n;			// ������ ��
public:
	Graph(const int vertices);
	~Graph();
	void PrintGraph();

	// Path
	void PrintPath(const int v);

	// Length
	void Insertlength(const int v, const int u, const int len);

	// Dist
	int choose(const int);
	void ShortestPath(const int v);
	void PrintDist();
};
#endif // GRAPH_H