#include <bits/stdc++.h>
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
    while (t--) {
        int S, D;
        cin >> S >> D;
        if (S > 9 * D || S < 1) {
            cout << "-1" << endl;
            continue;
        }
        vector<int> s(D, 0);
        for (int i = D - 1; i >= 0; i--) {
            if (S > 9) {
                s[i] = 9;
                S -= 9;
            }
            else {
                s[i] = S;
                S = 0;
            }
        }
        if (s[0] == 0) {
            for (int i = 1; i < D; i++) {
                if (s[i] > 0) {
                    s[i]--;
                    s[0] = 1;
                    break;
                }
            }
        }
        for (int i = 0; i < D; i++) {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}
