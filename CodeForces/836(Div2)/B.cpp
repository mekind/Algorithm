#include <iostream>
#include <string>
using namespace std;

int testcase, n, x;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> testcase;

	while (testcase--)
	{
		cin >> n;
		if (n & 1)
		{
			for (int i = 0; i < n; ++i)
				cout << "1 ";
			cout << "\n";
		}
		else
		{
			for (int i = 0; i < n - 2; ++i)
				cout << "2 ";
			cout << "1 3\n";
		}
	}

	return 0;
}