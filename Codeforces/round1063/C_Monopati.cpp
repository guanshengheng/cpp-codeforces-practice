#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pii = pair<int, int>;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(3, vector<int>(n + 1));
    vector<vector<pii>> pos(2 * n + 1);
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            pos[a[i][j]].push_back({i, j});
        }
    }

    int r1 = 0, r2 = n + 1;
    ll ans=0;
    for (int l = 1, r = 1; r <= 2 * n; r++)
    {
        while (r1 < n && a[1][r1 + 1] <= r && l <= a[1][r1 + 1])
            r1++;
        while (r2 > 1 && a[2][r2 - 1] <= r && l <= a[2][r2 - 1])
            r2--;
        while (r1 >= r2 && l <= r)
        {
            for (auto p : pos[l])
            {
                if (p.first == 1)
                {
                    r1 = min(r1, p.second - 1);
                }
                else
                {
                    r2 = max(r2, p.second + 1);
                }
            }
            l++;
        }
        ans += (l - 1);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}