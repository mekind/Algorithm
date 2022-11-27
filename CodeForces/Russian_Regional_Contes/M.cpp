#include <iostream>
#include <string>
#include <cmath>
#include <numeric>
using namespace std;

int testcase, n, a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> testcase;

    while (testcase--)
    {
        cin >> n;

        int sn = int(sqrt(n));
        int a = 1;
        int b = n;
        int mlcm = 2000000000;

        // cout << sn << "   sn\n";
        for (int i = 1; i <= sn; ++i)
        {
            if (n % i)
                continue;
            int aa = 1;
            int bb = n - 1;
            int nlcm = n - 1;
            if (i != 1)
            {
                aa = 1 * n / i;
                bb = n / i * (i - 1);
                nlcm = lcm(aa, bb);

                int aaa = 1 * i;
                int bbb = (n / i - 1) * i;

                int nnlcm = lcm(aaa, bbb);

                if (nnlcm < nlcm)
                {
                    aa = aaa;
                    bb = bbb;
                    nlcm = nnlcm;
                }
            }
            if (nlcm < mlcm)
            {
                mlcm = nlcm;
                a = aa;
                b = bb;
            }
        }

        cout << a << " " << b << "\n";
    }

    return 0;
}
