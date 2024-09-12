#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    int a[1000];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int cnt = n - 1;
    while (cnt >= 1 && a[cnt] > a[cnt + 1])
    {
        cnt--;
    }
    if (cnt == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << ' ';
        }
    }
    else
    {
        int j = n;
        while (a[cnt] > a[j])
        {
            j--;
        }
        swap(a[cnt], a[j]);
        reverse(a + cnt + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
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
