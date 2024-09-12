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
	cin.ignore();
	while (te--)
	{
		string s; getline(cin, s);
		int n = s.length();
		for (int i = 0; i < n; i++)
		{
			if (!isdigit(s[i])) s[i] = ' ';
		}
		stringstream ss(s);
		string token;
		vector<string> res;
		while (ss >> token)
		{
			res.push_back(token);
		}
		if (res.size() == 3) {
			ll a = stoll(res[0]);
			ll b = stoll(res[1]);
			ll c = stoll(res[2]);
			if (a + b == c) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			cout << "NO\n";
		}
	}
}