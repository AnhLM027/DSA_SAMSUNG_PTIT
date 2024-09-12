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
		ll dp[100005] = { 0 };
		dp[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				if (i >= j) dp[i] = (dp[i] + dp[i - j]) % MOD;
			}
		}
		cout << dp[n] << endl;
	}
}