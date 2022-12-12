#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;
typedef long long ll;

bool is_p[10000005];
vector<int> prime;

void pre()
{
    for (int i = 2; i < 10000005; i++)
    {
        if (is_p[i])
            continue;
        prime.push_back(i);
        for (int j = i; j < 10000005; j += i)
        {
            is_p[j] = true;
        }
    }
}

int sol(int a, int dif)
{
    bool is_prime = true;
    vector<int> ele;
    for (int i = 0; i < prime.size() && prime[i] <= sqrt(dif); i++)
    {
        if (dif % prime[i])
            continue;
        is_prime = false;
        ele.push_back(prime[i]);
        while (dif % prime[i] == 0)
        {
            dif /= prime[i];
        }
    }
    if (dif != 1)
        ele.push_back(dif);
    if (is_prime)
        return dif - a;
    int ret = 10000005;
    // cout << "hi\n";
    for (int i : ele)
    {
        // cout << i << " ddd\n";
        ret = min(ret, i - (a % i));
    }
    return ret;
}
int N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << gcd(10000, 100003) << " dd\n";
    // cout << 10009 % 97 << " dd\n";
    // cout << 20000 % 97 << " dd\n";
    cin >> N;
    pre();
    while (N--)
    {
        int a, b;
        int tmp;
        cin >> a >> b;
        tmp = max(a, b);
        b = min(a, b);
        a = tmp;
        int g = gcd(a, b);
        int dif = a - b;
        if (g != 1)
        {
            cout << "0\n";
            continue;
        }
        if (dif == 1)
        {
            cout << "-1\n";
            continue;
        }
        if ((dif % 2) == 0)
        {
            cout << 1 << "\n";
            continue;
        }

        // odd dif

        a %= dif;
        cout << sol(a, dif) << "\n";
    }
}

/*
너무 아쉽다.
일단 수학적 사고 능력이 많이 저하되어
문제를 푸는데 오래걸렸고
시간에 쫓기다 소인수 하나를 빼먹음

예) 2  * 1013 = 2016

2만 고려.
나누고 나머지도 생각해야 되는데...
*/