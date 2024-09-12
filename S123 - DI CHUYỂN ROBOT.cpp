#include <bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;




int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int x = 0, y = 0;
    int huong = 1;
    for (int i = 0; i < n; i++)
    {
        if (huong == 1) {
            if (s[i] == 'G') y++;
            else if (s[i] == 'L') x--, huong = 4;
            else if (s[i] == 'R') x++, huong = 2;
            else y--, huong = 3;
        }
        else if (huong == 2) {
            if (s[i] == 'G') x++;
            else if (s[i] == 'L') y++, huong = 1;
            else if (s[i] == 'R') y--, huong = 3;
            else x--, huong = 4;
        }
        else if (huong == 3) {
            if (s[i] == 'G') y--;
            else if (s[i] == 'L') x++, huong = 2;
            else if (s[i] == 'R') x--, huong = 4;
            else y++, huong = 1;
        }
        else if (huong == 4) {
            if (s[i] == 'G') x--;
            else if (s[i] == 'L') y--, huong = 3;
            else if (s[i] == 'R') y++, huong = 1;
            else x++, huong = 2;
        }
    }
    cout << x << " " << y;
}