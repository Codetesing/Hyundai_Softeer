#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

bool visited[MAX] = {false};
vector<vector<int>> graph(MAX, vector<int>());
vector<vector<int>> reversed_graph(MAX, vector<int>());

void check(bool *temp, int n) {
	for(int i = 1; i <= n; i++) {
		if(visited[i]) {
			temp[i] = true;
			visited[i] = false;
		}
	}
}

void DFS(int cur, int end) {
	visited[cur] = true;

	for(auto node:graph[cur]) {
		if(!visited[node]) {
			DFS(node, end);
		}
	}
}

void REVERSED_DFS(int cur, int end) {
	visited[cur] = true;

	for(auto node:reversed_graph[cur]) {
		if(!visited[node]) {
			REVERSED_DFS(node, end);
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, S, T;
	cin >> n >> m;

	bool StoT[MAX] = {false};
	bool TtoS[MAX] = {false};
	bool reversed_StoT[MAX] = {false};
	bool reversed_TtoS[MAX] = {false};

	int a, b;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		reversed_graph[b].push_back(a);
	}
	cin >> S >> T;
	
	visited[T] = true;
	DFS(S, T);
	check(StoT, n);
	visited[S] = true;
	DFS(T, S);
	check(TtoS, n);
	REVERSED_DFS(S, T);
	check(reversed_StoT, n);
	REVERSED_DFS(T, S);
	check(reversed_TtoS, n);

	int output = 0;
	for(int i = 1; i <= n; i++)
		if(StoT[i] && TtoS[i] && reversed_StoT[i] && reversed_TtoS[i] && i != S && i != T)
			output++;

	cout << output << '\n';

	return 0;
}
