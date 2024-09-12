#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

ll ucln(ll a, ll b) {
	while (a != 0) {
		ll x = a;
		a = b % a;
		b = x;
	}
	return b;
}

ll bcnn(ll a, ll b) {
	return a * b / ucln(a, b);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int te; cin >> te;
	while (te--)
	{
		int n;
		cin >> n;
		ll bc = 1;
		for (ll i = 1; i <= n; i++)
		{
			bc = bcnn(bc, i);
		}
		cout << bc << endl;
	}
}