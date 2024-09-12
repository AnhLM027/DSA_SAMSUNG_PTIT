#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll a[100005] = { 0 };
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll max_tmp = a[0];
        ll max_res = a[0];
        for (int i = 1; i < n; i++)
        {
            max_tmp = max(a[i], max_tmp + a[i]);
            max_res = max(max_res, max_tmp);
        }
        cout << max_res << endl;
    }
    return 0;
}
