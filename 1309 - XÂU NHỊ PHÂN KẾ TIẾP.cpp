#include <bits/stdc++.h>
using namespace std;
void next(string s) {
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '1') s[i] = '0';
        else {
            s[i] = '1';
            break;
        }
    }
    cout << s << endl;
}
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        next(s);
    }
    return 0;
}