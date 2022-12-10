#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int N, K, cnt;
int ans = -1;
int arr[500010], tmp[500010];

void merge(int start, int mid, int end)
{
    int i = start, j = mid + 1, t = 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            if (++cnt == K)
                ans = arr[i];
            tmp[t++] = arr[i++];
        }
        else
        {
            if (++cnt == K)
                ans = arr[j];
            tmp[t++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        if (++cnt == K)
            ans = arr[i];
        tmp[t++] = arr[i++];
    }
    while (j <= end)
    {
        if (++cnt == K)
            ans = arr[j];
        tmp[t++] = arr[j++];
    }
    i = start;
    t = 1;
    while (i <= end)
    {
        arr[i++] = tmp[t++];
    }
};

void merge_sort(int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(start, mid);
        merge_sort(mid + 1, end);

        merge(start, mid, end);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    merge_sort(0, N - 1);
    cout << ans;
}