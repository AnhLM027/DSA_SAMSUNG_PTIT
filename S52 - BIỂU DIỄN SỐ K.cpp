#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

int cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int te; cin >> te;
	while (te--)
	{
		int n, S; cin >> n >> S;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int dp[10000] = { 0 };
		dp[0] = 1;
		for (int s = 1; s <= S; s++)
		{
			for (int i = 0; i < n; i++)
			{
				if (s >= a[i])
				{
					dp[s] = (dp[s] + dp[s - a[i]]) % MOD;
				}
			}
		}
		cout << dp[S] % MOD << endl;
	}
}