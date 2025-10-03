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
    int N = 2 * n;
    vector<int> a(N + 2,0);
    for(int i = 1; i <= N; i++) cin >> a[i];

    vector<int> ans(n + 2, 0);
    for(int i = 2; i <= N; i += 2){
        ans[1] += a[i] - a[i - 1];
    }

    ans[2] = a[N] - a[1];
    for(int i = 2; i <= N - 1; i++){
        if(i & 1) ans[2] += a[i];
        else ans[2] -= a[i];
    }

    for(int k = 3; k <= n; k++){
        ans[k] = ans[k - 2] + 2 * (a[N - k + 2] - a[k - 1]);
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}