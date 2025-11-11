#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//t2水印检查
//赛时没有做出来，也没有获得部分分数。

//对于L等于256直接暴力，判断每个5*9矩形是否符合要求。
//具体就是遍历每个k，再遍历每个起点执行check函数

//但这样复杂度太大，正解是滑动窗口结合差分解决
//对于每个5*9矩形，找符合要求的k值区间，最后将所有被至少一个区间所包含过的k输出
//k大于等于st值为1的点+1的值，k小于st值为0的点，通过这个更新k的区间上下限，另外如果最大值小于最小值则这个矩形无效
//缀和判断目前的值

const int N = 2e2 + 7;
int n;
int L;
int A[N][N];
bool st[N][N];
const int M = 6e4 + 7;
int diff[M];

void init()
{
    st[1][1] = st[1][2] = st[1][4] = st[1][5] = st[1][7] = true;
    st[2][1] = st[2][2] = st[2][8] = true;
    st[3][1] = st[3][2] = st[3][3] = st[3][4] = st[3][7] = st[3][8] = true;
    st[4][7] = st[4][8] = true;
}

// bool check(int x, int y, int k)
// {
//     for (int i = x, a = 0; i < x + 5; i++, a++)
//     {
//         for (int j = y, b = 0; j < y + 9; j++, b++)
//         {
//             if ((A[i][j] < k) ^ st[a][b])
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }
void solve()
{
    init();
    cin >> n;
    cin >> L;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> A[i][j];
        }
    }

    for (int i = 1; i <= n - 4; i++)
    {
        for (int j = 1; j <= n - 8; j++)
        {

            int kn = 0;
            int km = L;
            bool fg = true;
            for (int a = 0; a < 5; a++)
            {
                for (int b = 0; b < 9; b++)
                {
                    if (st[a][b])
                    {
                        kn = max(kn, A[i + a][j + b] + 1);
                    }
                }
            }
            for (int a = 0; a < 5; a++)
            {
                for (int b = 0; b < 9; b++)
                {
                    if (st[a][b] == false)
                    {
                        if (A[i + a][j + b] < kn)
                        {
                            fg = false;
                        }
                        else
                            km = min(km, A[i + a][j + b]);
                    }
                }
            }

            if (fg && kn <= km)
            {
                diff[kn]++;
                diff[km + 1]--;
            }
        }
    }

    int cnt = 0;
    for (int k = 0; k < L; k++)
    {
        cnt += diff[k];
        if (cnt > 0)
        {
            cout << k << endl;
        }
    }
    // for (int k = 0; k < L; k++)
    // {
    //     bool fg = false;
    //     for (int i = 1; i <= n; i++)
    //     {
    //         for (int j = 1; j <= n; j++)
    //         {
    //             if (check(i, j, k))
    //             {
    //                 fg = true;
    //                 break;
    //             }
    //         }
    //         if (fg)
    //             break;
    //     }
    //     if (fg)
    //         cout << k << endl;
    // }
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