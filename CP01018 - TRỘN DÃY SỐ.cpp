#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int te; cin >> te;
	while (te--)
	{
		int n, k; cin >> n >> k;
		ll dp[1005][1005] = { 0 };
		dp[1][1] = 1;
		for (int i = 1; i <= n + k; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (j == 0 || j == i) dp[i][j] = 1;
				else dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j] % MOD) % MOD;
				//cout << dp[i][j] << " ";
			}
			//cout << endl;
		}
		cout << dp[n + k][k] << endl;
	}
}
