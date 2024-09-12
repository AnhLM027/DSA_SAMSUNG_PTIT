#include <bits/stdc++.h>
#define MAXN 20000005
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;


typedef long long ll;




int main() {
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		int cnt = 0;
		stack<int> st;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(') st.push(i);
			else {
				if (st.empty()) {
					cnt++;
					st.push(i);
				}
				else st.pop();
			}
		}
		cout << st.size() / 2 + cnt << endl;
	}
	return 0;
}