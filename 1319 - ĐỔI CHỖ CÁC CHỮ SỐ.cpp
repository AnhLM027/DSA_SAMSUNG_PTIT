#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

void solve() {
    int k; cin >> k;
    string s; cin >> s;
    int cnt = 0;
    while (k)
    {
        char max = s[cnt];
        int ind = -1;
        for (int i = s.length() - 1; i > cnt; i--)
        {
            if (s[i] > max)
            {
                max = s[i];
                ind = i;
            }
        }
        if (max != s[cnt])
        {
            swap(s[ind], s[cnt]);
            k--;
        }
        cnt++;
        if (cnt == s.length())
        {
            break;
        }
    }
    cout << s << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
