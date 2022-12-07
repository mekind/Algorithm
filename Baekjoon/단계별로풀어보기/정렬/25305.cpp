#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N, k, x[1010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> k;

    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
    }
    sort(x, x + N);

    cout << x[N - k];
}