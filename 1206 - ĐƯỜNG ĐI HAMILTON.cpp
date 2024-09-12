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

void DFS(int a, int cnt) {
    if (cnt == V) ok = true;
    visited[a] = true;
    for (int i : ke[a]) {
        if (!visited[i]) {
            DFS(i, cnt + 1);
        }
    }
    visited[a] = false;
}


int solve() {
    for (int i = 1; i <= V; i++)
    {
        memset(visited, false, sizeof(visited));
        ok = false;
        DFS(i, 1);
        if (ok) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int te; cin >> te;
    while (te--) {
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < 1000; i++) ke[i].clear();
        cin >> V >> E;
        for (int i = 0; i < E; i++) {
            int a, b; cin >> a >> b;
            ke[a].push_back(b);
            ke[b].push_back(a);
        }
        cout << solve() << endl;
    }
}