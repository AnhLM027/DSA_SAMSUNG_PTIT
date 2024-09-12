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
        string s;
        cin >> s;
        set<char> se;
        for (int i = 0; i < s.length(); i++) se.insert(s[i]);
        cout << se.size();
    }
    return 0;
}