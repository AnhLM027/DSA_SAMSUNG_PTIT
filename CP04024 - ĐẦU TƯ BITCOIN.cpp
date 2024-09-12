#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int te; te = 1;
	while (te--)
	{
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int check = 1;
		int lai = 0;
		for (int i = 0; i < n - 1; i++)
		{
			int min1 = *min_element(a.begin() + i + 1, a.end());
			if (a[i] >= min1) lai = max(lai, a[i] - min1), check = 0;
		}
		if (check)
		{
			cout << "Lo nang roi";
		}
		else cout << lai;
	}
}