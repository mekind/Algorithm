#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;

int testcase, k;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> testcase;

    while (testcase--)
    {
        cin >> s >> k;
        int now_min = s[0] - '0';
        int count_zero = 0;
        int pre_zero = 0;

        for (int i = 1; i < s.length(); ++i)
        {
            // cout << s << "   dd  " << i << "\n";
            if (k == 0)
                break;
            int now = s[i] - '0';

            // 0
            if (now == 0)
            {
                if (pre_zero && pre_zero + count_zero > i)
                {
                    // second zero zone
                    int between_num_start = pre_zero + count_zero;

                    int b_num = i - between_num_start;

                    s = s.substr(0, pre_zero + count_zero) + s.substr(pre_zero + count_zero + min(k, b_num));
                    k -= min(k, b_num);
                    i = pre_zero + count_zero;
                    count_zero += 1;
                    continue;
                }
                if (!count_zero)
                    pre_zero = i;
                count_zero += 1;
                // cout << "zero  " << count_zero << "\n";
                continue;
            }

            // not 0
            if (now_min < now)
            {
                if (s[i + 1] - '0' < now)
                {
                    s.erase(i, 1);
                    k -= 1;
                    if (s[i - 1] - '0')
                    {
                        i -= 2;
                        continue;
                    }
                    i -= 1;
                    continue;
                }
                now_min = now;
                continue;
            }
            if (now_min > now)
            {
                // cout << pre_zero << "  " << count_zero << " " << k << "  ddd \n ";
                now_min = now;
                if (pre_zero && pre_zero + count_zero <= k)
                {
                    // cout << "  how? \n";
                    s = s.substr(pre_zero + count_zero);
                    k -= (pre_zero + count_zero);
                    pre_zero = 0;
                    count_zero = 0;
                    i = 0;
                    continue;
                }
                else
                {
                    int start = pre_zero + count_zero;
                    for (int idx = i - 1; idx >= start; --idx)
                    {
                        int nnow = s[idx] - '0';
                        if (nnow > now)
                        {
                            s.erase(idx, 1);
                            k -= 1;
                        }

                        if (!k)
                            break;
                    }

                    i = start;
                    continue;
                }
            }
        }
        if (k)
        {
            s = s.substr(0, s.length() - k);
        }
        cout << s << "\n";
    }

    return 0;
}
