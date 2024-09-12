#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;
const int INF = 1e9;
typedef pair<int, int> ii;


struct edge
{
    int x, y, w;
};
int V, E, st;
vector<edge> ds;
int d[1005];

bool check(int s) {
    d[s] = 0;
    for (int i = 1; i <= V - 1; i++) {
        for (edge e : ds) {
            int u = e.x, v = e.y, w = e.w;
            if (d[u] < INF) {
                d[v] = min(d[v], d[u] + w);
            }
        }
    }
    bool ok = false;
    for (edge e : ds) {
        if (d[e.x] < INF) {
            if (d[e.y] > d[e.x] + e.w) {
                ok = true; break;
            }
        }
    }
    return ok;
}

bool ktrachutrinham() {
    for (int i = 1; i <= V; i++) d[i] = INF;
    bool res = false;
    for (int i = 1; i <= V; i++)
    {
        if (d[i] == INF) {
            if (check(i)) {
                res = true;
                break;
            }
        }
    }
    return res;

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int te; cin >> te;
    while (te--) {
        ds.clear();
        cin >> V >> E;
        for (int i = 0; i < E; i++)
        {
            int x, y, w; cin >> x >> y >> w;
            edge tmp = { x,y,w };
            ds.push_back(tmp);
        }
        if (ktrachutrinham()) cout << "1\n";
        else cout << "0\n";
    }
}