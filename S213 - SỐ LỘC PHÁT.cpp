#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

// "Le Minh Anh"
typedef long long ll;

vector<string> res;

int cmp(string a, string b) {
	if (a.length() == b.length())
	{
		return a > b;
	}
	return a.length() > b.length();
}
void init(int n) {
	queue<string> qe;
	qe.push("6");
	qe.push("8");
	int cnt = 0;
	while (1)
	{
		string s = qe.front();
		if (s.length() > n) {
			cout << cnt << endl;
			break;
		}
		res.push_back(s);
		qe.pop();
		string s1 = s + "6";
		string s2 = s + "8";
		qe.push(s1);
		qe.push(s2);
		cnt++;
	}
	sort(res.begin(), res.end(), cmp);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
}

int main() {
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		init(n);
		res.clear();
	}
	return 0;
}