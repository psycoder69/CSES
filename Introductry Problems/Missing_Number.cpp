#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

int main()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int n, x;
    cin >> n;

    vector <bool> nums(n+1, 0);

    for (int i = 1; i < n; i ++) cin >> x, nums[x] = 1;

    for (int i = 1; i <= n; i ++)
    {
        if (not nums[i])
        {
            cout << (i);
            break;
        }
    }

    return 0;
}