#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

struct edge {
    int x, y, w;
};
vector<edge> dscanh;
bool visited[1001];
int V, E;
int parent[1001];
int sz[1001];

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool Union(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    else {
        if (sz[u] > sz[v]) parent[v] = u, sz[u] += sz[v];
        else parent[u] = v, sz[v] += sz[u];
        return true;
    }
}

void Kruskal() {
    sort(dscanh.begin(), dscanh.end(), [](edge a, edge b)->bool {
        return a.w < b.w;
        });
    ll ts = 0;
    vector<edge> MST;
    for (int i = 0; i < E; i++)
    {
        if (MST.size() == V - 1) break;
        edge tmp = dscanh[i];
        if (Union(tmp.x, tmp.y)) {
            MST.push_back(tmp);
            ts += tmp.w;
        }
    }
    cout << ts << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int te; cin >> te;
    while (te--) {
        dscanh.clear();
        memset(visited, false, sizeof(visited));
        cin >> V >> E;
        for (int i = 0; i < E; i++)
        {
            int x, y, w; cin >> x >> y >> w;
            dscanh.push_back({ x,y,w });
        }
        for (int i = 1; i <= V; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
        Kruskal();
    }
}
