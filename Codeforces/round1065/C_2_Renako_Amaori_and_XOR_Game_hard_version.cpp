#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


//所有元素进行异或，异或得到数为零则平局
//不为零则从最高位依次往下看，找为一的位i
//从后往前看遍历两个数组，找到第一个有一个数组里的元素这个位是1的，且另一个数组的元素不是

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int x = a[1];
    for (int i = 2; i <= n; i++)
        x = a[i] ^ x;
    for (int i = 1; i <= n; i++)
        x = b[i] ^ x;
    if (x == 0)
    {
        cout << "Tie" << endl;
        return;
    }
    vector<int> bits;
    while (x)
    {
        bits.push_back(x % 2);
        x /= 2;
    }
    int len = bits.size();
    for (int i = len - 1; i >= 0; i--)
    {
        if (bits[i])
        {
            for (int j = n; j >= 1; j--)
            {
                if (((a[j] >> i) & 1) ^ ((b[j] >> i) & 1))
                {
                    if (j % 2 == 1)
                        cout << "Ajisai" << endl;
                    else
                        cout << "Mai" << endl;
                    return;
                }
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        // cout<<114514<<endl;
        solve();
    }
    return 0;
}