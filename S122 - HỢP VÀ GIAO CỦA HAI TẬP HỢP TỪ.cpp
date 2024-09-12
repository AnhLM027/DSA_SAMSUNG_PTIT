#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

// "Le Minh Anh"
typedef long long ll;

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    for (int i = 0; i < s.length(); i++) s[i] = tolower(s[i]);
    for (int i = 0; i < t.length(); i++) t[i] = tolower(t[i]);
    stringstream ss(s);
    string token;
    set<string> a, b;
    while (ss >> token) a.insert(token);
    stringstream st(t);
    string token2;
    while (st >> token2) b.insert(token2);
    map<string, int> mp;
    for (string x : a) {
        mp[x]++;
    }
    for (string x : b) {
        mp[x]++;
    }
    for (pair<string, int> x : mp) {
        if (x.second >= 1)
        {
            cout << x.first << " ";
        }
    }
    cout << endl;
    for (pair<string, int> x : mp) {
        if (x.second > 1)
        {
            cout << x.first << " ";
        }
    }
    return 0;
}