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
		string s, t;
		cin >> s >> t;
		int n = s.length();
		int m = t.length();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1));
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				if (i == 0 || j == 0) dp[i][j] = 0;
				else if (s[i - 1] == t[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
		cout << dp[n][m] << endl;
	}
}
