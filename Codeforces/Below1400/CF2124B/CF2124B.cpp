#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int a[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (a[1] >= a[2])
    cout << a[1] + a[2] << endl;
  else
    cout << 2 * a[1] << endl;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin>>t;
  while (t--) {
    solve();
  }
  return 0;
}