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
        int n;
        cin >> n;
        int a[1000005] = { 0 };
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a[x]++;
        }
        for (int i = 0; i <= 1000000; i++)
        {
            if (a[i] % 2 != 0)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
