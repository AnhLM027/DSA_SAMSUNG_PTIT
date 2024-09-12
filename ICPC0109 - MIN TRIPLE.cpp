#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

// "Le Minh Anh"
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        ll m1 = INT_MAX, m2 = INT_MAX, m3 = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ll x; cin >> x;
            if (x <= m1)
            {
                m3 = m2; m2 = m1; m1 = x;
            }
            else if (m1 < x && x <= m2) {
                m3 = m2;
                m2 = x;
            }
            else if (m2 < x && x <= m3) m3 = x;
            /*cout << m1 << " " << m2 << " " << m3 << endl;*/
        }
        if (m2 == INT_MAX)
        {
            m2 = m1;
            m3 = m1;
        }
        else if (m3 == INT_MAX) m3 = m2;
        cout << m1 + m2 + m3 << endl;
    }
    return 0;
}
