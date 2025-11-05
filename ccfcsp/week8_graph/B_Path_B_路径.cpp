#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


//可以通过一些欧拉图关于度的性质解决
//也可以通过直接使用dfs进行搜索,如果最大深度为4则符合


vector<int>adj[5];
bool visited[5];
int maxl=0;
void dfs(int u, int curl){
    visited[u]=true;
    maxl=max(maxl,curl);
    for(int v:adj[u]){
        if(!visited[v]){
            dfs(v,curl+1);
            // cout<<maxl<<endl;
        }
    }
}
void solve() {
    for(int i=1;i<=3;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=4;i++){
        dfs(i,1);
        // cout<<maxl<<endl;
    }
    if(maxl==4)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}