#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;


int n, s;
vector<int> a;
int res = INT_MAX;
ll sum = 0;
void Try(int cnt, int st) {
    if (sum >= s || cnt >= res || cnt == n)
    {
        if (sum == s) res = min(cnt, res);
        return;
    }
    for (int j = st; j < n; j++)
    {
        sum += a[j];
        Try(cnt + 1, j + 1);
        sum -= a[j];
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end(), greater<int>());
    Try(0, 0);
    if (res == INT_MAX) cout << "-1";
    else cout << res;
    return 0;
}