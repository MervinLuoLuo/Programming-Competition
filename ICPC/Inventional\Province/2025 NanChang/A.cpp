#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n, k;cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1,a.end(),greater<int>());

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(ans - i + a[i] >= (n - i) * k){
            int res = max(0ll,(n - i) * k - ans + i);
            if(res == 0) ans++;
            else ans += res;
            break;
        }
        else ans += a[i];
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
