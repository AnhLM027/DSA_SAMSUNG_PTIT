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
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		vector<ll> dp(k + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= k; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i >= a[j])
				{
					dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
				}
			}
		}
		cout << dp[k] << endl;
	}
}