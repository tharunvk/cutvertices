#include <bits/stdc++.h>
using namespace std;

void cututil(vector<int> adj[], int u, bool visited[],	int disc[], int low[], int& time, int parent,bool iscutvertices[])
{
	int children = 0;
	visited[u] = true;
	disc[u] = low[u] = ++time;
	for (auto v : adj[u]) {
		if (!visited[v]) {
			children++;
			cututil(adj, v, visited, disc, low, time, u, iscutvertices);
			low[u] = min(low[u], low[v]);
			if (parent != -1 && low[v] >= disc[u])
				iscutvertices[u] = true;
		}
		else if (v != parent)
			low[u] = min(low[u], disc[v]);
	}
	if (parent == -1 && children > 1)
		iscutvertices[u] = true;
}

void cutvertices(vector<int> adj[], int V)
{
	int disc[V] = { 0 };
	int low[V];
	bool visited[V] = { false };
	bool iscutvertices[V] = { false };
	int time = 0, par = -1;

	for (int u = 0; u < V; u++)
		if (!visited[u])
			cututil(adj, u, visited, disc, low,
				time, par, iscutvertices);

	for (int u = 0; u < V; u++)
		if (iscutvertices[u] == true)
			cout << u << " ";
}

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{

	cout << "Cut vertices set are \n";
	int V = 5;
	vector<int> adj[V];
	addEdge(adj, 0,1);
	addEdge(adj, 1,2);
	addEdge(adj, 2,3);
	addEdge(adj, 3,1);
	addEdge(adj, 0,2);
	cutvertices(adj, V);

	return 0;
}
