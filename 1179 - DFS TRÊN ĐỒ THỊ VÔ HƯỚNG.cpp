#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

bool visited[10000];

void DFS(int u, vector<int> ke[]) {
	cout << u << " ";
	visited[u] = true;
	for (int i : ke[u]) {
		if (!visited[i])
		{
			DFS(i, ke);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		memset(visited, false, sizeof(visited));
		int V, E, u;
		cin >> V >> E >> u;
		vector<int> ke[10000];
		for (int i = 0; i < E; i++)
		{
			int a, b; cin >> a >> b;
			ke[a].push_back(b);
			ke[b].push_back(a);
		}
		DFS(u, ke);
		cout << endl;
	}
}