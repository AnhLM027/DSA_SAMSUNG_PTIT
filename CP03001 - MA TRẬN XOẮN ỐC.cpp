#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int cnt = 1;
    int a[100][100] = { 0 };
    int c1 = 0, c2 = n - 1, h1 = 0, h2 = n - 1;
    while (c1 <= c2 && h1 <= h2)
    {
        for (int i = c1; i <= c2; i++)
        {
            a[h1][i] = cnt++;
        }
        h1++;
        for (int i = h1; i <= h2; i++)
        {
            a[i][c2] = cnt++;
        }
        c2--;
        for (int i = c2; i >= c1; i--)
        {
            a[h2][i] = cnt++;
        }
        h2--;
        for (int i = h2; i >= h1; i--)
        {
            a[i][c1] = cnt++;
        }
        c1++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
