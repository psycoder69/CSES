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

    if ((n < 2) or (n > 3))
    {
        for (int x = 2; x <= n; x += 2) cout << (x) << " ";
        for (int x = 1; x <= n; x += 2) cout << (x) << " ";
    }
    else cout << "NO SOLUTION";

    return 0;
}