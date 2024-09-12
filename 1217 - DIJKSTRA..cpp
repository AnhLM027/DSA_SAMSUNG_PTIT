#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;



int V, E, st;
typedef pair<int, int> ii;
vector<ii> ds[1001];

void Dijkstra(int s) {
    vector<int> dp(V + 1, INT_MAX);
    dp[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({ 0,s });
    while (!pq.empty()) {
        ii tmp = pq.top(); pq.pop();
        int u = tmp.second, w = tmp.first;
        if (w > dp[u]) continue;
        for (auto x : ds[u]) {
            int v = x.first, kc = x.second;
            if (dp[v] > dp[u] + kc) {
                dp[v] = dp[u] + kc;
                pq.push({ dp[v],v });
            }
        }
    }
    for (int i = 1; i <= V; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int te; cin >> te;
    while (te--) {
        for (int i = 0; i < 1001; i++) ds[i].clear();
        cin >> V >> E >> st;
        for (int i = 0; i < E; i++)
        {
            int x, y, w; cin >> x >> y >> w;
            ds[x].push_back({ y,w });
            ds[y].push_back({ x,w });
        }
        Dijkstra(st);
    }
}