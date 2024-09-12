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
int V, E, s, t;
void DFS(int a, string s) {
    visited[a] = true;
    for (auto i : ke[a]) {
        if (!visited[i]) {
            if (i == t) {
                res = s + " " + to_string(i);
            }
            DFS(i, s + " " + to_string(i));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int te; cin >> te;
    while (te--) {
        for (int i = 0; i < 1000; i++) ke[i].clear();
        memset(visited, false, sizeof(visited));
        res = "-1";
        cin >> V >> E >> s >> t;
        for (int i = 0; i < E; i++) {
            int a, b; cin >> a >> b;
            ke[a].push_back(b);
        }
        DFS(s, to_string(s));
        cout << res << endl;
    }
}
