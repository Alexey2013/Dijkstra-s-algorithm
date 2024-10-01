#ifndef  _DIJKSTRA_H
#define  _DIJKSTRA_H
#include "vector.h"
#include "dheap.h"
#include "pair.h"

Vector<Vector<Pair<int, int>>> generate(int n, int m) {
	int k = n * (n - 1) / 2;
	m = Min(k,n);
	Vector<Vector<Pair<int, int>>> result(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n && cnt < m; ++j, ++cnt) {
			int l = rand() % 10 + 1;
			result[i].push_back( Pair<int, int>(j, l));
			result[j].push_back(Pair<int, int>(i, l));
		}
	}
	return result;
}

void Dijkstra(Vector<int>& dist, Vector<int>& up, int n, int d, int start) {
	Vector<int> key(n + 1, INT_MAX);
	Vector<int> index(n + 1);
	Vector<int> name(n + 1);

	Vector<Vector<Pair<int, int>>>  graph = generate(20,29);
	Vector<int> current;
	for (int i = 1; i <= n; ++i) {
		up[i] = 0;
		dist[i] = INT_MAX;
		index[i] = i;
		name[i] = i;
	}

	key[start] = 0;

	DHeap dHeap(d);

	while (!dHeap.isEmpty()) {
		int i = dHeap.extractMin().first;
		dist[i] = dHeap.extractMin().second;

		Vector<Pair<int, int>> current(graph[i]);
		int count=0;
		while (count< current.size()) {
			int j = current[count].first;
			int jq = index[j];

			if (dist[jq] == INT_MAX) {
				if (key[jq] > dist[i] + current[count].second) {
					key[jq] = dist[i] + current[count].second;
					dHeap.decreaseKey(jq, key[jq]);
					up[j] = i;
				}
			}
			count++;
		}
	}
}


#endif 