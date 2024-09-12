#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;


//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
//1 5 10 10 5 1

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        ll dp[1005][1005] = { 0 };
        dp[0][0] = 1;
        for (int i = 1; i <= n + 1; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                if (j == 1 || j == i)
                {
                    dp[i][j] = 1;
                }
                else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }
        cout << dp[n + 1][k + 1] << endl;
    }
    return 0;
}