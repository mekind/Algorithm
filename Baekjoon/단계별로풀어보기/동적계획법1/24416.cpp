#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int arr[55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    arr[1] = 1;
    arr[2] = 1;
    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    cout << arr[n] << " " << n - 2;
}