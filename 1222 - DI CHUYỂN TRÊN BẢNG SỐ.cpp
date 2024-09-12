#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
const int INF = 1e9;

int n, m;
int a[maxn][maxn];
int dp[maxn][maxn];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            dp[i][j] = INF;
        }
    }

    dp[0][0] = a[0][0];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ a[0][0], {0, 0} });

    while (!pq.empty()) {
        pair<int, int> pos = pq.top().second;
        pq.pop();
        int x = pos.first, y = pos.second;

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (isValid(nx, ny)) {
                if (dp[nx][ny] > dp[x][y] + a[nx][ny]) {
                    dp[nx][ny] = dp[x][y] + a[nx][ny];
                    pq.push({ dp[nx][ny], {nx, ny} });
                }
            }
        }
    }

    cout << dp[n - 1][m - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}