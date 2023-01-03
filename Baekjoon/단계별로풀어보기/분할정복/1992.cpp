#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N;
string s[100];

void sol(int x, int y, int n) {
    int b = 0, w = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[x + i][y + j] == '1')
                b++;
            else
                w++;
        }
    }
    if (b == 0) {
        cout << "0";
        return;
    }
    if (w == 0) {
        cout << "1";
        return;
    }
    cout << "(";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            sol(x + i * n / 2, y + j * n / 2, n / 2);
        }
    }
    cout << ")";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    sol(0, 0, N);

    return 0;
}