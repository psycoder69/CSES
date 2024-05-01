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

    vector <int> nums(n);

    for (int& num : nums) cin >> num;

    long long int moves = 0;

    for (int i = 1; i < n; i ++)
    {
        if (nums[i-1] > nums[i])
        {
            moves += (nums[i-1] - nums[i]);
            nums[i] = nums[i-1];
        }
    }

    cout << (moves);

    return 0;
}