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
        ll a[100005] = { 0 };
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll b[100005];
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int check = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] <= a[j])
                {
                    check = 0;
                }
            }
            if (check)
            {
                b[cnt++] = a[i];
            }
        }
        sort(b, b + cnt, greater<int>());
        for (int i = 0; i < cnt; i++)
        {
            cout << b[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
