#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	// Sap xep giam dan
	priority_queue<ll, vector<ll>, greater<ll>> qp;
	for (int i = 0; i < n; i++)
	{
		ll x; cin >> x;
		qp.push(x);
	}
	ll res = 0;
	while (qp.size() > 1)
	{
		ll x = qp.top(); qp.pop();
		ll y = qp.top(); qp.pop();
		qp.push(x + y);
		res += x + y;
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}