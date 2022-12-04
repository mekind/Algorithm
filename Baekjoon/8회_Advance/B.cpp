#include <iostream>
#include <algorithm>
using namespace std;

int N, M, X, Y;
int arr[500010];
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= M; ++i)
        cin >> arr[i];
    arr[0] = 0;
    arr[M + 1] = N + 1;
    cin >> X >> Y;

    sort(arr, arr + M + 2);

    for (int i = 1; i <= M; ++i)
    {
        if (arr[i - 1] + X > N)
            continue;
        int idx = upper_bound(arr, arr + M, arr[i - 1] + X) - arr;
        int cnt = idx - i - 1;
        ans = max(ans, M - max(Y, cnt));
    }
    cout << ans << "\n";
}