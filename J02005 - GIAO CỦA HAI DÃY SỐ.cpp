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
    int t; t = 1;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        set<int> sa, sb;
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (!sa.count(x))
            {
                sa.insert(x);
                a.push_back(x);
            }
        }
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            if (!sb.count(x))
            {
                sb.insert(x);
                b.push_back(x);
            }
        }
        map<int, int> res;
        for (int i = 0; i < a.size(); i++) res[a[i]]++;
        for (int i = 0; i < b.size(); i++) res[b[i]]++;
        for (pair<int, int> x : res) {
            if (x.second == 2) cout << x.first << " ";
        }
        cout << endl;
    }
    return 0;
}