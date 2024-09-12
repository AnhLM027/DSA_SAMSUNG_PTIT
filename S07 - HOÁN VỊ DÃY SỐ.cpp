#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

int b[100];
int n;
int a[100];
void in(int b[]) {
    for (int i = 0; i < n; i++)
    {
        cout << a[b[i]] << ' ';
    }
    cout << endl;
}
bool check[1000] = { false };
void Try(int i) {

    for (int j = 0; j < n; j++)
    {
        if (!check[j])
        {
            b[i] = j;
            if (i == n - 1)
            {
                in(b);
            }
            check[j] = 1;
            Try(i + 1);
            check[j] = 0;
        }

    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    Try(0);
    return 0;
}
