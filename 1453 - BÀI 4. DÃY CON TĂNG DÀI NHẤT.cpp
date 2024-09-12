#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(ans.begin(), ans.end(), a[i]);
        if (it == ans.end()) {
            ans.push_back(a[i]);
        }
        else *it = a[i];
    }
    cout << ans.size();
}
