#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

void solve() {
	ll n, k;
	cin >> n >> k;
	if (k % 2 == 1)
	{
		cout << "1" << endl;
	}
	else
	{
		int cnt = 1;
		while (k % 2 == 0)
		{
			k /= 2;
			cnt++;
		}
		cout << cnt << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}