#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//考察了度的基本概念

void solve()
{
    int n;
    cin >> n;
    vector<int> d(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        d[a]++;
        d[b]++;
    }
    bool isstar = false;
    for (int i =1;i<=n;i++)
    {
        if (d[i] == n - 1)
        {
            isstar = true;
            break;
        }
    }
    if (isstar)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}