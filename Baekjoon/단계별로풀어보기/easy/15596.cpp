#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long sum(vector<int> &a)
{
    long long ret = 0;
    for (int i = 0; i < a.size(); ++i)
        ret += a[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}