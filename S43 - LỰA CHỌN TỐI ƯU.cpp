#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

int cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int te; cin >> te;
	while (te--)
	{
		int n; cin >> n;
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].first >> a[i].second;
		}
		sort(a.begin(), a.end(), cmp);
		/*for (int i = 0; i < n; i++)
		{
			cout << a[i].first << " " << a[i].second << endl;
		}*/
		int end = a[0].second;
		int cnt = 1;
		for (int i = 1; i < n; i++)
		{
			if (a[i].first >= end)
			{
				end = a[i].second;
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}