#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

int main()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int n;
    cin >> n;

    int steps = 0;

    while (n)
    {
        int x = 0;

        for (int y = n; y > 0; y /= 10) x = max(x, y % 10);

        n -= x;
        steps ++;
    }

    cout << (steps);

    return 0;
}