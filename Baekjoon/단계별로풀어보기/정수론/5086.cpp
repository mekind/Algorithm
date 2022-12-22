#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        int a, b;

        cin >> a >> b;
        if (!a && !b) {
            break;
        }
        if (b % a == 0) {
            cout << "factor\n";
        } else if (a % b == 0) {
            cout << "multiple\n";
        } else
            cout << "neither\n";
    }
}