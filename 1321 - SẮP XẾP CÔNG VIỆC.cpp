#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;
int cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> res;
	vector<int> a;
	vector<int> b;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		b.push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		pair<int, int> tmp;
		tmp.first = a[i];
		tmp.second = b[i];
		res.push_back(tmp);
	}
	sort(res.begin(), res.end(), cmp);
	int ans = 0;
	int i = 1;
	int cnt = 1;
	while (i < n)
	{
		if (res[ans].second <= res[i].first)
		{
			ans = i;
			cnt++;
		}
		i++;
	}
	cout << cnt << endl;
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