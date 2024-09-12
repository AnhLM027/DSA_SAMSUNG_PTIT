#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

// "Le Minh Anh"
typedef long long ll;

int main() {
    int n; cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (x > 0) sum += (ll)x * 2;
    }
    cout << sum;
    return 0;
}
