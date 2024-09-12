#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (k == 0) {
            cout << "NO\n";
            continue;
        }
        int l = 0, r = 0;
        ll sum = 0;
        bool ok = false;
        while (r < n) {
            sum += a[r];
            while (sum > k && l <= r) {
                sum -= a[l];
                l++;
            }
            if (sum == k) {
                ok = true;
                break;
            }
            r++;
        }
        if (!ok) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}