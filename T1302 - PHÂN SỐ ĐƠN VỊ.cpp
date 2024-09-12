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
		ll tu, mau;
		cin >> tu >> mau;
		ll res;
		while (1)
		{
			if (mau % tu == 0)
			{
				cout << "1/" << mau / tu << endl;
				break;
			}
			else
			{
				res = mau / tu + 1;
				cout << "1/" << res << " + ";
				tu = tu * res - mau;
				mau = mau * res;
			}
		}
	}
}