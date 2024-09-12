#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

// "Le Minh Anh"
typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--)
    {
        int n, k; cin >> n >> k;
        if (n < k) cout << "0\n";
        else
        {
            ll tich = 1;
            for (int i = 1; i <= k; i++)
            {
                tich *= (ll)n - k + i;
                tich %= MOD;
            }
            cout << tich << endl;
        }
    }
    return 0;
}