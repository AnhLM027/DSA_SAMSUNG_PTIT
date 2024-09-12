#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;
vector<char> a;

void Try(int i, int n, vector<char> s, int st) {
    for (int j = st; j < n; j++)
    {
        a.push_back(s[j]);
        for (char x : a) {
            cout << x;
        }
        cout << ' ';
        Try(i + 1, n, s, j + 1);
        a.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<char> s;
        for (int i = 0; i < n; i++)
        {
            char x; cin >> x;
            s.push_back(x);
        }
        Try(0, n, s, 0);
        cout << endl;
    }
    return 0;
}
