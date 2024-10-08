#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        for (int i = 1; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                if (i % 2 == 0)
                {
                    cnt++;
                }
                if ((n / i) % 2 == 0)
                {
                    cnt++;
                }
                if (i % 2 == 0 && i * i == n)
                {
                    cnt--;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
