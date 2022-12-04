#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int A, B;

    cin >> A >> B;

    int t;
    cin >> t;

    int h = t / 60;
    int m = t % 60;
    A = (A + h + (B + m) / 60) % 24;
    B = (B + m) % 60;

    cout << A << " " << B;
}