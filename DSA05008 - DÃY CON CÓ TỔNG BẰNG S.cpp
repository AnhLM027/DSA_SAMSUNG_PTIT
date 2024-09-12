#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

// "Le Minh Anh"
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int s; cin >> s;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int dp[400000] = { 0 };

        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = s; j >= a[i]; j--)
            {
                if (dp[j - a[i]])
                {
                    dp[j] = 1;
                }
            }
        }
        if (dp[s]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}