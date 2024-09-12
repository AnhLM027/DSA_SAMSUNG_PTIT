#include <iostream>
using namespace std;

int a[1000];
int n;

void in(int a[]) {
	for (int i = 1; i <= n; i++)
	{
		cout << a[i];
	}
	cout << ' ';
}
bool check[1000] = { false };
void Try(int i) {
	if (i == n + 1) {
		in(a);
		return;
	}
	for (int j = n; j >= 1; j--) {
		if (!check[j]) {
			a[i] = j;
			check[j] = true;
			Try(i + 1);
			check[j] = false;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		Try(1);
		cout << endl;
	}

}