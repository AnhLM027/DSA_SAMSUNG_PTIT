#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;
int snt(int n) {
    if (n < 2)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int check(int n) {
    int sum = 0;
    while (n > 0)
    {
        int x = n % 10;
        if (x != 3 && x != 2 && x != 5 && x != 7)
        {
            return 0;
        }
        sum += x;
        n /= 10;
    }
    return snt(sum);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int cnt = 0;
        for (int i = l; i <= r; i++)
        {
            if (check(i) && snt(i))
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
