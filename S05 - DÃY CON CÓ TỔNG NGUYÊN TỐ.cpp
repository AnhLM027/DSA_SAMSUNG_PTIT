#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

// "Le Minh Anh"
typedef long long ll;


int snt(int n) {
	if (n < 2) return 0;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	int t; cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end(), greater<int>());
		vector<vector<int>> res;
		for (int i = 0; i < (1 << n); i++)
		{
			int sum = 0;
			vector<int>b;
			for (int j = 0; j < n; j++)
			{
				if (i & (1 << j)) {
					sum += a[j];
					b.push_back(a[j]);
				}
			}
			if (snt(sum)) res.push_back(b);
		}
		sort(res.begin(), res.end());
		for (vector<int> x : res) {
			for (int i = 0; i < x.size(); i++) {
				cout << x[i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
