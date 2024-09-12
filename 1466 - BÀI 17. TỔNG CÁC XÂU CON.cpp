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
		string s; cin >> s;
		int l = s.length();
		ll sum = 0;
		for (int i = 0; i < l; i++)
		{
			string t = "";
			for (int j = i; j < l; j++)
			{
				t += s[j];
				sum += stoll(t);
				//cout << t << endl;
			}
		}
		cout << sum << endl;
	}
}