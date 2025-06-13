#include <iostream>
#include <vector>
using namespace std;

struct Edge {
	int capacity, to;
};

void dfs(vector<vector<Edge>>& g, int node, vector<bool>& visited, int currentSum, int& maxPath) {
    visited[node] = true;

    bool isLeaf = true;
    for (const Edge& edge : g[node]) {
        if (!visited[edge.to]) {
            isLeaf = false;
            dfs(g, edge.to, visited, currentSum + edge.capacity, maxPath);
        }
    }

    if (isLeaf) {
        maxPath = max(maxPath, currentSum);
    }

    visited[node] = false;
}

int findMax(vector<vector<Edge>>& g, int n) {
    int maxPath = 0;
    for (int i = 0; i < n; ++i) {
        vector<bool> visited(n, false);
        dfs(g, i, visited, 0, maxPath);
    }
    return maxPath;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	cout << "Введите количество вершин и ребер графа: ";
	cin >> n >> m;
	vector<vector<Edge>> g(n);
	for (int i = 0; i < m; i++) {
		cout << "Введите вершины(откуда и куда) и пропускную способность ребра: ";
		int from, to, capacity;
		cin >> from >> to >> capacity;
		g[from].push_back({ capacity, to });
		g[to].push_back({ capacity, from });
	}
	cout << "Максимальный путь в графе: " << findMax(g, n) << '\n';
	return 0;
}
