#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

//是一种贪心的算法，比较容易想到且可以通过
//但是码量略大，且时间复杂度是nlogn
//使用了循环链表和小根堆优先队列
//优先队列保证了所找到的元素是当前最小，循环链表方便O(1)进行查询左右元素
//然后遍历每个元素，取左右较小的那个，进行删除和更新的操作
//重新连接链表，将更新后的节点放入优先队列，原节点和被删除的节点不再使用

struct cycle
{
    int val;
    int l;
    int r;
    bool vis = true;
};

void solve()
{

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<cycle> cyc(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cyc[i].val = a[i];
        cyc[i].l = (i - 2 + n) % n + 1;
        cyc[i].r = (i) % n + 1;
    }
    priority_queue<PII, vector<PII>, greater<PII>> q;
    for (int i = 1; i <= n; i++)
    {
        q.push({a[i], i});
    }
    ll ans = 0;
    int T = n;
    while (T>1)
    {
        auto [val, id] = q.top();
        q.pop();

        if (!cyc[id].vis || cyc[id].val != val)
            continue;

        auto [_val, l, r, vis] = cyc[id];
        int p;
        if (cyc[l].val > cyc[r].val)
            p = r;
        else
            p = l;

        int mval = max(cyc[p].val, cyc[id].val);
        ans += mval;
        cyc[id].val = mval;
        cyc[p].vis = false;

        if (p == l)
        {
            cyc[id].l = cyc[p].l;
            cyc[cyc[p].l].r = id;
        }
        else
        {
            cyc[id].r = cyc[p].r;
            cyc[cyc[p].r].l = id;
        }

        q.push(PII{mval, id});
        T--;
    }
    cout << ans << endl;
}

// //求环的最小生成树的性质，所有边的权重和减去最小边
// void solve() {
//     int n;
//     cin>>n;
//     vector<int>a(n+1);
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//     }
//     vector<int>b;
//     for(int i=1;i<n;i++){
//         b.push_back(max(a[i],a[i+1]));
//     }
//     b.push_back(max(a[n],a[1]));
//     ll sum=0;
//     ll mx=0;
//     for(int i:b){
//         sum+=i;
//         mx=max(1LL*i,mx);
//     }
//     cout<<sum-mx<<endl;

// }

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