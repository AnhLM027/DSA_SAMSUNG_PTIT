#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int a[500][500], dp[501][501] = { 0 };
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
			}
		}
		dp[0][0] = a[0][0];
		for (int i = 1; i < n; i++)
		{
			dp[i][0] = dp[i - 1][0] + a[i][0];
		}
		for (int i = 1; i < m; i++)
		{
			dp[0][i] = dp[0][i - 1] + a[0][i];
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				dp[i][j] = min({ dp[i - 1][j - 1],dp[i][j - 1],dp[i - 1][j] }) + a[i][j];
			}
		}
		cout << dp[n - 1][m - 1] << endl;
	}
}