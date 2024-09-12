#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

// "Le Minh Anh"
typedef long long ll;

char s;
int n;

void Try(char x, string t) {
	for (int j = x; j <= s; j++)
	{
		t += char(j);
		if (t.length() == n)
		{
			cout << t << endl;
		}
		else Try(j, t);
		t.pop_back();
	}
}

int main() {
	cin >> s;
	cin >> n;
	Try('A', "");
	return 0;
}