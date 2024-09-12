#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;
vector<string> res;
void Lapphuong() {
	for (ll i = 0; i <= 1000; i++)
	{
		ll tmp = i * i * i;
		res.push_back(to_string(tmp));
	}
}

bool check(string a, string b) {
	int i = 0, j = 0;
	while (i < a.length() && j < b.length()) {
		if (a[i] == b[j]) {
			i++; j++;
		}
		else i++;
	}
	return j == b.length();
}

void solve() {
	string s;
	cin >> s;
	for (ll i = res.size() - 1; i >= 0; i--)
	{
		if (check(s, res[i])) {
			cout << res[i] << endl;
			return;
		}
	}
	cout << "-1" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Lapphuong();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}