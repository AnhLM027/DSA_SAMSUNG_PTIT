#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

void Try(int i, int s, vector<int>& a, vector<int>& tmp, vector<vector<int>>& res) {
    if (s == 0)
    {
        res.push_back(tmp);
        return;
    }
    for (int j = i; j < a.size(); j++)
    {
        if (s < a[j])
        {
            break;
        }
        tmp.push_back(a[j]);
        Try(j, s - a[j], a, tmp, res);
        tmp.pop_back();
    }
}

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<vector<int>> res;
    vector<int> tmp;
    Try(0, s, a, tmp, res);
    if (res.empty())
    {
        cout << "-1" << endl;
        return;
    }
    for (auto x : res) {
        cout << "[";
        for (int i = 0; i < x.size(); i++)
        {
            cout << x[i];
            if (i != x.size() - 1)
            {
                cout << " ";
            }
        }
        cout << "]";
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
