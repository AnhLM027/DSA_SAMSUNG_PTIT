#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

// "Le Minh Anh"
typedef long long ll;

int cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    int n, m; cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mp[x]++;
    }
    vector<pair<int, int>> res;
    for (pair<int, int> x : mp) {
        res.push_back(x);
    }
    sort(res.begin(), res.end(), cmp);
    /*for (pair<int, int> x : res) {
        cout << x.first << " " << x.second << endl;
    }*/
    int maxse = res[res.size() - 1].second;
    int check = 1;
    for (int i = res.size() - 1; i >= 0; i--) {
        if (res[i].second != maxse)
        {
            check = 0;
            maxse = res[i].second;
            break;
        }
    }
    int ind = -1;
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i].second == maxse)
        {
            ind = res[i].first;
            break;
        }
    }
    if (check != 1)
    {
        cout << ind;
    }
    else cout << "NONE";
    return 0;
}