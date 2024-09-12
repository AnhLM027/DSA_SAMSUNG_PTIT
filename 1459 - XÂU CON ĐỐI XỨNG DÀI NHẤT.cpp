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
	while (t--)
	{
		string s; cin >> s;
		int n = s.length();
		s = '@' + s;
		bool F[n + 1][n + 1] = { false };
		for (int i = 1; i <= n; i++) F[i][i] = true;
		int ans = 1;
		for (int len = 2; len <= n; len++)
		{
			for (int i = 1; i <= n - len + 1; i++)
			{
				int j = i + len - 1;
				if (len == 2) F[i][j] = (s[i] == s[j]);
				else
				{
					F[i][j] = (s[i] == s[j] && F[i + 1][j - 1]);
				}
				if (F[i][j])
				{
					ans = max(ans, len);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}