#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
typedef long long ll;
#define PI 3.141592653589793238



int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int ans = INT_MIN;
		int dp[100005];
		fill(dp, dp + n, 1);
		for (int i = 1; i < n; i++)
		{
			if (a[i - 1] < a[i]) {
				dp[i] += dp[i - 1];
			}
		}
		int dp2[100005];
		fill(dp2, dp2 + n, 1);
		for (int i = n - 2; i >= 0; i--)
		{
			if (a[i] > a[i + 1]) {
				dp2[i] += dp2[i + 1];
			}
		}
		for (int i = 0; i < n; i++)
		{
			//cout << dp[i] << " " << dp2[i] << endl;
			ans = max(ans, dp[i] + dp2[i] - 1);
		}
		cout << ans << endl;
	}
	return 0;
}