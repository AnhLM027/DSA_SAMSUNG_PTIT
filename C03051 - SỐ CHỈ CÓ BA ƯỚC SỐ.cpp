#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

int snt(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        int x = sqrt(l);
        int y = sqrt(r);
        if (x * x < l)
        {
            x++;
        }
        int cnt = 0;
        for (int i = x; i <= y; i++)
        {
            if (snt(i)) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
