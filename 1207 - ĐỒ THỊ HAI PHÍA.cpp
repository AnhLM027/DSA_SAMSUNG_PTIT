#include <bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

vector<int> ke[1001];
bool visited[1001];
int V, E;
bool ok;
int color[1001];
void DFS(int a) {
    visited[a] = true;
    for (int i : ke[a]) {
        if (!visited[i]) {
            color[i] = 3 - color[a];
            DFS(i);
        }
        else if (color[i] == color[a]) {
            ok = false;
            return;
        }
    }
}




int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int te; cin >> te;
    while (te--) {
        memset(visited, false, sizeof(visited));
        memset(color, 0, sizeof(color));
        ok = true;
        for (int i = 0; i < 1000; i++) ke[i].clear();
        cin >> V >> E;
        for (int i = 0; i < E; i++) {
            int a, b; cin >> a >> b;
            ke[a].push_back(b);
            ke[b].push_back(a);
        }
        for (int i = 1; i <= V; i++)
        {
            if (!color[i]) {
                color[i] = 1;
                DFS(i);
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
