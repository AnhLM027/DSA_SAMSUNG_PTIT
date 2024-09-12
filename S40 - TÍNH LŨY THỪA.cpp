#include <bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;


typedef long long ll;

ll mul(ll a, ll b) {
    if (b == 0) return 0;
    ll ans = mul(a, b / 2);
    ans = (ans + ans) % MOD;
    if (b % 2 == 1) ans = (ans + a) % MOD;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (1)
    {
        ll a, b; cin >> a >> b;
        if (a == 0 && b == 0)
        {
            return 0;
        }
        ll tmp = 1;
        while (b)
        {
            if (b % 2 == 1)
            {
                tmp = mul(tmp, a) % MOD;
            }
            a = mul(a, a) % MOD;
            b /= 2;
        }
        cout << tmp << endl;
    }
}