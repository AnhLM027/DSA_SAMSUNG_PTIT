#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[1000];
    a[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    int cnt = k;
    while (cnt >= 1 && a[cnt] == a[cnt - 1] + 1)
    {
        cnt--;
    }
    if (cnt == 0)
    {
        for (int i = n - k + 1; i <= n; i++)
        {
            cout << i << ' ';
        }
    }
    else
    {
        a[cnt]--;
        for (int i = cnt + 1; i <= k; i++)
        {
            a[i] = n - k + i;
        }
        for (int i = 1; i <= k; i++)
        {
            cout << a[i] << ' ';
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
