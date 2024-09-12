#include <bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;


//Phuong phap nhan ma tran + luy thua nhi phan

typedef long long ll;

vector<vector<ll>> fibo(vector<vector<ll>> a, vector<vector<ll>> b, int sz) {
    vector<vector<ll>> res(sz, vector<ll>(sz));
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            res[i][j] = 0;
            for (int k = 0; k < sz; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return res;
}

vector<vector<ll>> binPow(vector<vector<ll>> a, int sz, int* n) {
    vector <vector<ll>> tmp(sz, vector<ll>(sz));
    tmp = a;
    while (*n > 0)
    {
        if (*n % 2 == 1)
        {
            tmp = fibo(tmp, a, sz);
        }
        *n /= 2;
        a = fibo(a, a, sz);
    }
    return tmp;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int sz;
        cin >> sz;
        int n;
        cin >> n;
        n--;
        vector<vector<ll>> a(sz, vector<ll>(sz));
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                cin >> a[i][j];
            }
        }
        vector<vector<ll>>out(sz, vector<ll>(sz));
        out = binPow(a, sz, &n);
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                cout << out[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}