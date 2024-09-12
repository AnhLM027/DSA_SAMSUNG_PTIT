#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k;
    cin >> n >> k;
    int m = 0;
    ll j = 1;
    for (ll i = n; i >= 1; i--)
    {
        j *= i;
        while (j % 2 == 0)
        {
            m++;
            j /= 2;
        }
    }
    if (m >= k)
    {
        cout << "Yes";
    }
    else cout << "No";

    return 0;
}
