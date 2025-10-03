#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(2 * n + 2);
    for(int i = 1; i <= 2 * n; i++) cin >> a[i];

    vector<int> ans(n + 1,0);
    for(int i = 2; i <= 2 * n; i += 2) ans[1] = max(ans[1],a[i] - a[i - 1]);

    ans[2] = a[2 * n] - a[1];
    int add = 0;
    for(int i = 3; i <= 2 * n - 1; i += 2) add = max(add,a[i] - a[i - 1]);
    ans[2] += add;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}