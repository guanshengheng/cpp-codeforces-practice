#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//求环的最小生成树的性质，所有边的权重和减去最小边
void solve() {
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int>b;
    for(int i=1;i<n;i++){
        b.push_back(max(a[i],a[i+1]));
    }
    b.push_back(max(a[n],a[1]));
    ll sum=0;
    ll mx=0;
    for(int i:b){
        sum+=i;
        mx=max(1LL*i,mx);
    }
    cout<<sum-mx<<endl;

}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}