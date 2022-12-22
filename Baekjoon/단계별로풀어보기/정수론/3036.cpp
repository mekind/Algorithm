#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int first_r = 0;
    for (int i = 0; i < N; i++) {
        if (!i) {
            cin >> first_r;
            continue;
        }
        int tmp;
        cin >> tmp;

        int gg = gcd(first_r, tmp);

        cout << first_r / gg << "/" << tmp / gg << "\n";
    }
}