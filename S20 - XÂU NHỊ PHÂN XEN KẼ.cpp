#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 1003
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

// "Le Minh Anh"
typedef long long ll;


int a[1000];
int n;
void Try(int i) {
    for (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if (i > 1 && a[i] == a[i - 1])
        {
            continue;
        }
        else if (i == n)
        {
            for (int k = 1; k <= n; k++)
            {
                cout << a[k] << " ";
            }
            cout << endl;
        }
        else Try(i + 1);
    }
}
int main() {
    cin >> n;
    Try(1);
    return 0;
}