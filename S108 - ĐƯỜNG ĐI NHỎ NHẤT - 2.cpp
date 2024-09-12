#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int maxn = 505;

int n, m;
int a[maxn][maxn];
int dist[maxn][maxn];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dijkstra() {
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    pq.push({ a[0][0], {0, 0} });
    dist[0][0] = a[0][0];

    while (!pq.empty()) {
        int d = pq.top().first;
        pair<int, int> pos = pq.top().second;
        pq.pop();
        int x = pos.first, y = pos.second;

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (dist[nx][ny] > dist[x][y] + a[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + a[nx][ny];
                    pq.push({ dist[nx][ny], {nx, ny} });
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            dist[i][j] = INF;
        }
    }

    dijkstra();

    cout << dist[n - 1][m - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}