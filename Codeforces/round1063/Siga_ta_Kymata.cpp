#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//只有边缘和最值不会被修改，特判一下即可

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    string x;
    cin >> x;
    int mp, np;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == 1)
            np = i;
        if (p[i] == n)
            mp = i;
    }
    if(x[0]=='1'||x[n-1]=='1'||x[np-1]=='1'||x[mp-1]=='1'){
        cout<<-1<<endl;
        return;
    }
    cout<<5<<endl;
    cout<<1<<" "<<np<<endl;
    cout<<1<<" "<<mp<<endl;
    cout<<np<<" "<<n<<endl;
    cout<<mp<<" "<<n<<endl;
    cout<<min(np,mp)<<" "<<max(np,mp)<<endl;
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