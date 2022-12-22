#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<int, int> mpx, mpy;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int ansx = 0, ansy = 0;
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        if (mpx.find(x) != mpx.end())
            mpx[x] += 1;
        else
            mpx[x] = 1;

        if (mpy.find(y) != mpy.end())
            mpy[y] += 1;
        else
            mpy[y] = 1;
    }

    for (auto i = mpx.begin(); i != mpx.end(); i++) {
        if (i->second == 1 || i->second == 3) ansx = i->first;
    }

    for (auto i = mpy.begin(); i != mpy.end(); i++) {
        if (i->second == 1 || i->second == 3) ansy = i->first;
    }

    cout << ansx << " " << ansy;
}