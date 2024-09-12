#include <bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;


// Tinh so Fibonacci lon >= 10^8
//Phuong phap nhan ma tran + luy thua nhi phan

typedef long long ll;
ll dp[2][2];
vector<vector<ll>> fibo(vector<vector<ll>> a, vector<vector<ll>> b) {
    vector<vector<ll>> res(2, vector<ll>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return res;
}

ll binPow(vector<vector<ll>> a, int* n) {
    vector <vector<ll>> tmp(2, vector<ll>(2));
    tmp[0][0] = 1; tmp[0][1] = 1;
    tmp[1][0] = 1; tmp[1][1] = 0;
    if (*n == 1)
    {
        return a[0][1];
    }
    while (*n > 0)
    {
        if (*n % 2 == 1)
        {
            tmp = fibo(tmp, a);
        }
        *n /= 2;
        a = fibo(a, a);
    }
    return tmp[0][1];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n--;
        vector<vector<ll>> a(2, vector<ll>(2));
        a[0][0] = 1; a[0][1] = 1;
        a[1][0] = 1; a[1][1] = 0;
        cout << binPow(a, &n) << endl;
    }
    return 0;
}