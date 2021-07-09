#pragma once
#ifndef GRAPH_H
#define GRAPH_H

class Graph {
private:
	int** length;	// 이차원 배열
	int* dist;		// 일차원 배열
	int* path;		// 일차원 배열
	bool* s;		// 일차원 배열
	int n;			// 정점의 수
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