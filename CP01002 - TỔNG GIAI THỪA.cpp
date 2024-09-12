#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    ll sum = 0;
    ll res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
        sum += res;
    }
    cout << sum;
    return 0;
}
