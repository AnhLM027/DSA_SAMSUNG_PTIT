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

bool taken[1001];
int V, E;
typedef pair<int, int> ii;
vector<ii> ds[1001];

void Prim(int s) {
    taken[s] = true;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (auto x : ds[s]) {
        int t = x.first;
        if (!taken[t]) {
            // pq luu { trong so, dinh }
            pq.push({ x.second,t });
        }
    }
    ll res = 0, cnt = 0;
    while (!pq.empty()) {
        ii tmp = pq.top(); pq.pop();
        int u = tmp.second, w = tmp.first;
        if (!taken[u]) {
            res += w;
            cnt++;
            taken[u] = true;
            for (auto a : ds[u]) {
                if (!taken[a.first]) {
                    pq.push({ a.second,a.first });
                }
            }
        }
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int te; cin >> te;
    while (te--) {
        for (int i = 0; i < 1001; i++) ds[i].clear();
        memset(taken, false, sizeof(taken));
        cin >> V >> E;
        for (int i = 0; i < E; i++)
        {
            int x, y, w; cin >> x >> y >> w;
            ds[x].push_back({ y,w });
            ds[y].push_back({ x,w });
        }
        Prim(1);
    }
}
