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
		int n, V; cin >> n >> V;
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].first;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].second;
		}
		ll dp[1005] = { 0 };
		for (int i = 0; i < n; i++)
		{
			for (int j = V; j >= a[i].first; j--)
			{
				dp[j] = max(dp[j - a[i].first] + a[i].second, dp[j]);
			}
		}
		ll max1 = 0;
		for (int i = 0; i <= V; i++)
		{
			max1 = max(max1, dp[i]);
		}
		cout << max1 << endl;
	}
}