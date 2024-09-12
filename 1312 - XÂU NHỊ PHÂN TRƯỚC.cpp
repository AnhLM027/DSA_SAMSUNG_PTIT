#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int i = s.length() - 1;
    while (i >= 1 && s[i] == '0')
    {
        i--;
    }
    if (i == 0)
    {
        for (int j = 0; j < s.length(); j++)
        {
            cout << "1";
        }
        cout << endl;
    }
    else
    {
        s[i] = '0';
        for (int j = i + 1; j < s.length(); j++)
        {
            s[j] = '1';
        }
        cout << s << endl;
    }
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
