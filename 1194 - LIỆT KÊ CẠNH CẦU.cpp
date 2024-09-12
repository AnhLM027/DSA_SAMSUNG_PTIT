#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

set<int> ke[1001];
bool visited[1001];
string res;
int V, E, u, v;
int dem;
vector<pair<int, int>> dske;
void BFS(int a) {
    visited[a] = true;
    for (int i : ke[a])
    {
        if (!visited[i])
        {
            BFS(i);
        }
    }
}
int tplt() {
    dem = 0;
    for (int i = 1; i <= V; i++)
    {
        if (!visited[i])
        {
            dem++;
            BFS(i);
        }
    }
    return dem;
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
            ke[a].insert(b);
            ke[b].insert(a);
            dske.push_back({ a,b });

        }
        sort(dske.begin(), dske.end());
        int cnt = tplt();
        for (int i = 0; i < E; i++)
        {
            memset(visited, false, sizeof(visited));
            int x = dske[i].first, y = dske[i].second;
            ke[x].erase(y);
            ke[y].erase(x);
            if (cnt < tplt()) cout << x << " " << y << " ";
            ke[x].insert(y);
            ke[y].insert(x);
        }
        dske.clear();
        cout << endl;
    }
}