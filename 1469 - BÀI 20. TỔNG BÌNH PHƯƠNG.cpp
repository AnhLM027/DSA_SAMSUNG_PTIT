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
		int n; cin >> n;
		int dp[1000000];
		for (int i = 1; i <= n; i++) {
			dp[i] = i;
			for (int j = 1; j <= sqrt(i); j++)
				dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
		cout << dp[n] << endl;
	}
}