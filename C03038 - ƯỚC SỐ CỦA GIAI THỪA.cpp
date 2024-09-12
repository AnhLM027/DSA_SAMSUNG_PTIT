#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int te; cin >> te;
	while (te--)
	{
		int n, p; cin >> n >> p;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			int j = i;
			while (j % p == 0)
			{
				j /= p;
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}