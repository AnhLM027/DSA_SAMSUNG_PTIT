#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<string> res;
	for (int i = 0; i < n; i++)
	{
		string s;
		for (int j = 0; j < n; j++)
		{
			char x;
			cin >> x;
			s.push_back(x);
		}
		res.push_back(s);
	}
	vector<string> b;
	queue<pair<int, int>> q;
	queue<string> p;
	q.push({ 0, 0 });
	p.push("");
	if (res[0][0] == '0' || res[n - 1][n - 1] == '0') {
		cout << "-1" << endl;
		return;
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		string tmp = p.front();
		q.pop();
		p.pop();
		if (x == n - 1 && y == n - 1) {
			b.push_back(tmp);
		}
		if (x + 1 < n && res[x + 1][y] == '1') {
			q.push({ x + 1, y });
			p.push(tmp + "D");
		}
		if (y + 1 < n && res[x][y + 1] == '1') {
			q.push({ x, y + 1 });
			p.push(tmp + "R");
		}
	}
	if (b.empty())
	{
		cout << -1 << endl;
		return;
	}
	sort(b.begin(), b.end());
	for (string x : b)
	{
		cout << x << " ";
	}
	cout << endl;
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