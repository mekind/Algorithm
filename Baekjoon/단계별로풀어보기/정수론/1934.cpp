#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> testcase;

    while (testcase--) {
        int A, B;

        cin >> A >> B;

        cout << lcm(A, B) << "\n";
    }
}