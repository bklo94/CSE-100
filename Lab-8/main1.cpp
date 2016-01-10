#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 101;
bool visit[MAX_N] = {0};
vector<int> adjacent[MAX_N], rev[MAX_N], order;
vector< vector<int> > SCC;

/*
STRONGLY-CONNECTED-COMPONENTS(G)
1 call DFS(G) to compute finishing times u.f for each vertex u
2 compute G^T
3 call DFS(G^T), but in the main loop of DFS, consider the vertices
in order of decreasing u.f (as computed in line 1)
4 output the vertices of each tree in the depth-first forest formed in line 3 as a
separate strongly connected component
*/

void DFS(vector<int> graph[], vector<int> &res, int i) {
	visit[i] = true;
	for(int j = 0; j < graph[i].size(); j++) {
		if(!visit[graph[i][j]]) {
			DFS(graph, res, graph[i][j]);
		}
	}
	res.push_back(i);
}

int main() {
	int i, j, u, v, numVertices, numEdges, SCC_count = 0, set = 0, temp = 0;
	cin >> numVertices >> numEdges;
	for(i = 0; i < numEdges; i++) {
		cin >> u >> v;
		adjacent[u].push_back(v);
	}
	for(i = 0; i < numVertices; i++) {
		visit[i] = false;
	}
	for(i = 0; i < numVertices; i++) {
		if(!visit[i]) {
			DFS(adjacent, order, i);
		}
	}
	for(i = 0; i < numVertices; i++) {
		for(j = 0; j < adjacent[i].size(); j++) {
			rev[adjacent[i][j]].push_back(i);
		}
	}
	for(i = 0; i < numVertices; i++) {
		visit[i] = false;
	}
	reverse(order.begin(), order.end());
	for(i = 0; i < order.size(); i++) {
		if(!visit[order[i]]) {
			vector<int> component;
			DFS(rev, component, order[i]);
			SCC.push_back(component);
		}
	}
	for(i = 0; i < SCC.size(); i++) {
		SCC_count++;
	}
	cout << SCC_count <<endl;
	return 0;
}