#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

vector<int> ke[1001];
bool visited[1001];
string res;
int V, E, u, v;
int parent[1000];
int ok;
void DFS(int a) {
    visited[a] = true;
    for (int i : ke[a])
    {
        if (!visited[i])
        {
            parent[i] = a;
            DFS(i);
        }
        else if (parent[a] != i) ok = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int te; cin >> te;
    while (te--) {
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < 1000; i++) ke[i].clear();
        cin >> V >> E;
        for (int i = 0; i < E; i++)
        {
            int a, b; cin >> a >> b;
            ke[a].push_back(b);
            ke[b].push_back(a);
        }
        ok = 0;
        for (int i = 1; i <= V; i++)
        {
            if (!visited[i])
            {
                DFS(i);
            }
        }
        if (!ok) cout << "NO\n";
        else cout << "YES\n";
    }
}
