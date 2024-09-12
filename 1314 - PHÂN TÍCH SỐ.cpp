#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void phantich(int* ok, int* cnt, int a[]) {
    int i = *cnt;
    while (i >= 1 && a[i] == 1)
    {
        i--;
    }
    if (i == 0)
    {
        *ok = 0;
    }
    else
    {
        a[i]--;
        int d = *cnt - i + 1;
        int q = d / a[i];
        int r = d % a[i];
        *cnt = i;
        if (q)
        {
            for (int j = 0; j < q; j++)
            {
                ++(*cnt);
                a[*cnt] = a[i];
            }
        }
        if (r)
        {
            a[++(*cnt)] = r;
        }
    }
}

void solve() {
    int n; cin >> n;
    int ok = 1;
    int a[1000];
    a[1] = n;
    int cnt = 1;
    vector<vector<int>> res;
    while (ok)
    {
        vector<int> b;
        for (int i = 1; i <= cnt; i++)
        {
            b.push_back(a[i]);
        }
        res.push_back(b);
        phantich(&ok, &cnt, a);
    }
    for (vector<int> x : res) {
        cout << "(";
        for (int i = 0; i < x.size(); i++)
        {
            cout << x[i];
            if (i != x.size() - 1)
            {
                cout << " ";
            }
        }
        cout << ") ";
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
