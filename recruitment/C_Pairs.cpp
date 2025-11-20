#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//第一个数中就包含一个需要的数，不妨令这个为x
//找到不含x的数对，如果是YES那么这个数对里要有一个是y
//不含x的数对应该每个都有y
//执行两遍即可，a1、b1分别作为x

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1);
    vector<int> b(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> a[i] >> b[i];
    int cntx = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    int cnt4 = 0;
    bool fgx = false;
    int y1, y2;
    for (int i = 2; i <= m; i++)
    {
        if (a[i] != a[1] && b[i] != a[1])
        {
            cntx++;
            if (!fgx)
            {
                fgx = true;
                y1 = a[i];
                y2 = b[i];
            }
            if (a[i] == y1 || b[i] == y1)
            {
                cnt1++;
            }
            if (a[i] == y2 || b[i] == y2)
            {
                cnt2++;
            }
        }
    }
    if (cnt1 == cntx)
    {
        cout << "YES" << endl;
        return;
    }
    if (cnt2 == cntx)
    {
        cout << "YES" << endl;
        return;
    }
    fgx=false;
    cntx=0;
    for (int i = 2; i <= m; i++)
    {
        if (a[i] != b[1] && b[i] != b[1])
        {
            cntx++;
            if (!fgx)
            {
                fgx = true;
                y1 = a[i];
                y2 = b[i];
            }
            if (a[i] == y1 || b[i] == y1)
            {
                cnt3++;
            }
            if (a[i] == y2 || b[i] == y2)
            {
                cnt4++;
            }
        }
    }
    // cout<<cnt4<<" "<<cntx<<endl;
    if (cnt3 == cntx)
    {
        cout << "YES" << endl;
        return;
    }
    if (cnt4 == cntx)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    return;
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