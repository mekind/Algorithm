#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int x[3], y[3], r[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> testcase;
    while (testcase--) {
        cin >> x[0] >> y[0] >> r[0] >> x[1] >> y[1] >> r[1];

        if (x[0] == x[1] && y[0] == y[1] && r[0] == r[1]) {
            cout << "-1\n";
            continue;
        }

        int disx = (x[0] - x[1]) * (x[0] - x[1]);
        int disy = (y[0] - y[1]) * (y[0] - y[1]);
        int rr = r[0] + r[1];

        double dis = sqrt(disx + disy);

        if (dis == rr)
            cout << "1\n";
        else if (dis + min(r[0], r[1]) == max(r[0], r[1]))
            cout << "1\n";
        else if (abs(r[0] - r[1]) < dis && dis < rr)
            cout << "2\n";
        else
            cout << "0\n";
    }
}