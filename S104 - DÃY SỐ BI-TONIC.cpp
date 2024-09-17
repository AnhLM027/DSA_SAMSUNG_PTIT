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
		for (int i = 0; i < n; i++) {
			int dp[1000] = { 0 };
			for (int j = 0; j <= i; j++) {
				dp[j] = a[j];
				for (int k = 0; k < j; k++) {
					if (a[k] < a[j]) {
						dp[j] = max(dp[k] + a[j], dp[j]);
					}
				}
			}
			//cout << dp[i] << "-";
			int dp2[1000] = { 0 };
			for (int j = n - 1; j >= i; j--) {
				dp2[j] = a[j];
				for (int k = n - 1; k > j; k--) {
					if (a[k] < a[j]) {
						dp2[j] = max(dp2[k] + a[j], dp2[j]);
					}
				}
			}
			//cout << dp2[i] << endl;
			ans = max(ans, dp[i] + dp2[i] - a[i]);
		}
		cout << ans << endl;
	}
	return 0;
}