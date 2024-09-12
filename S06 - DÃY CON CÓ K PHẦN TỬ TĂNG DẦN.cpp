#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

// "Le Minh Anh"
typedef long long ll;


vector<vector<int>> res;
int n, k;
void Try(int i, int st, vector<int> a, vector<int> b) {
	for (int j = st; j <= n; j++)
	{
		b[i] = j;
		if (i == k)
		{
			vector<int> tmp;
			for (int l = 0; l < k; l++)
			{
				tmp.push_back(a[b[l]]);
			}
			res.push_back(tmp);
			return;
		}
		else Try(i + 1, j + 1, a, b);
	}
}
int main() {
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		int ok = 1;
		vector<int> b(n + 1);
		//for (int i = 0; i < n; i++) b[i] = i;
		Try(0, 0, a, b);
		sort(res.begin(), res.end());
		for (auto x : res) {
			for (int i = 0; i < k; i++)
			{
				cout << x[i] << " ";
			}
			cout << endl;
		}
		res.clear();
	}
	return 0;
}