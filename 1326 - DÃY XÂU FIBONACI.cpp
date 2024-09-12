#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;
//A
//B
//A|B
//B|AB
//AB|BAB
//BAB|ABBAB
// k<=f[n-2] tiep tuc tim o s1
// k>f[n-2] : x+len(s1)==k
// => x=k-len(s1);
// x la gia tri k moi trong s2

ll f[100] = { 0 };
char chia(ll n, ll k) {
	if (n == 1) return 'A';
	if (n == 2) return 'B';
	if (k <= f[n - 2]) return chia(n - 2, k);
	else return chia(n - 1, k - f[n - 2]);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= 92; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	int t; cin >> t;
	while (t--)
	{
		ll n, k; cin >> n >> k;
		cout << chia(n, k) << endl;
	}

}