#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> testcase;

    while (testcase--) {
        int startx, starty;
        int endx, endy, n;

        cin >> startx >> starty >> endx >> endy;

        cin >> n;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int X, Y, R;
            cin >> X >> Y >> R;
            int sdis = (X - startx) * (X - startx) + (Y - starty) * (Y - starty);
            int edis = (X - endx) * (X - endx) + (Y - endy) * (Y - endy);
            if (sdis < R * R && edis < R * R) continue;

            if (sdis < R * R) ans++;
            if (edis < R * R) ans++;
        }

        cout << ans << "\n";
    }
}