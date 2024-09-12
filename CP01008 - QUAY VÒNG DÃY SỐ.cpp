#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

void solve() {
	int n, d;
	cin >> n >> d;
	queue<int> qe;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		qe.push(x);
	}
	queue<int> tmp;
	while (d--)
	{
		int x = qe.front();
		qe.pop();
		tmp.push(x);
	}
	while (!qe.empty())
	{
		cout << qe.front() << " ";
		qe.pop();
	}
	while (!tmp.empty())
	{
		cout << tmp.front() << " ";
		tmp.pop();
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