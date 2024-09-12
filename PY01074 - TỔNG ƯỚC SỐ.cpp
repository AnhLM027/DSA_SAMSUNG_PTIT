#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

// "Le Minh Anh"
typedef long long ll;

#define lm 2000000

int p[lm] = { 0 };

void prime() {
    p[0] = 0, p[1] = 0;
    for (int i = 2; i <= sqrt(lm); i++)
    {
        for (int j = i * i; j <= lm; j += i)
        {
            if (p[j] == 0) p[j] = i;
        }
    }
    for (int i = 2; i <= lm; i++)
    {
        if (p[i] == 0)
        {
            p[i] = i;
        }
    }
}

void solve(int n, vector<int> a, ll& sum) {
    for (int i = 0; i < a.size(); i++)
    {
        while (a[i] > 1)
        {
            ;
            sum += p[a[i]];
            a[i] /= p[a[i]];
        }
    }
}
int main() {
    prime();
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll sum = 0;
    solve(n, a, sum);
    cout << sum;
    return 0;
}
