#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;

    cin >> n;
    int cnt2 = 0, cnt5 = 0;
    for (int i = 1; i <= n; i++) {
        int now = i;
        while (now % 2 == 0) {
            cnt2++;
            now /= 2;
        }
        while (now % 5 == 0) {
            cnt5++;
            now /= 5;
        }
    }

    cout << min(cnt2, cnt5);
}