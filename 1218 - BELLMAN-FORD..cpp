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
bool check;

void BellmanFord(int s) {
    check = true;
    fill(d + 1, d + V + 1, INF);
    d[s] = 0;
    for (int i = 1; i <= V - 1; i++) {
        check = true;
        for (edge e : ds) {
            int u = e.x, v = e.y, w = e.w;
            if (d[u] < INF) {
                if (d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                    check = false;
                }
            }
        }
        if (check) break;
    }
    if (check) {
        for (int i = 1; i <= V; i++)
        {
            if (d[i] == INF) cout << "INFI ";
            else cout << d[i] << " ";
        }
    }
    else cout << "-1";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int te; cin >> te;
    while (te--) {
        ds.clear();
        cin >> V >> E >> st;
        for (int i = 0; i < E; i++)
        {
            int x, y, w; cin >> x >> y >> w;
            edge tmp = { x,y,w };
            ds.push_back(tmp);
        }
        BellmanFord(st);
    }
    //cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
    return 0;
}