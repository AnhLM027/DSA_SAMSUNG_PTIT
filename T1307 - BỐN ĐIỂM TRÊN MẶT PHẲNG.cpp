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
		vector<vector<int>> res(4, vector<int>(3));
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> res[i][j];
			}
		}
		for (int i = 1; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				res[i][j] = res[i][j] - res[0][j];
				//cout << res[i][j] << " ";
			}
			//cout << endl;
		}
		vector<int> tmp(3);
		tmp[0] = res[2][2] * res[1][1] - res[2][1] * res[1][2];
		tmp[1] = res[1][2] * res[2][0] - res[1][0] * res[2][2];
		tmp[2] = res[1][0] * res[2][1] - res[1][1] * res[2][0];
		int sum = tmp[0] * res[3][0] + tmp[1] * res[3][1] + tmp[2] * res[3][2];
		if (sum == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}