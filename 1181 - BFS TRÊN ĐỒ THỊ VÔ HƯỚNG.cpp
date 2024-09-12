#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

vector<int> ke[1001];
bool visited[1001];
int V, E, u, v;
void BFS(int a) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int x = q.front(); q.pop();
        cout << x << " ";
        for (int i : ke[x])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int te; cin >> te;
    while (te--) {
        cin >> V >> E >> u;
        for (int i = 0; i < 1000; i++) ke[i].clear();
        for (int i = 0; i < E; i++)
        {
            int a, b; cin >> a >> b;
            ke[a].push_back(b);
            ke[b].push_back(a);
        }
        memset(visited, false, sizeof(visited));
        BFS(u);
        cout << endl;
    }
}