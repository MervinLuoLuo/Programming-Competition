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
    int n,k;cin >> n >> k;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int m;cin >> m;
    vector<int> val(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        val[i] = k - (a[i] % k);
        ans += a[i] / k;
    }

    sort(val.begin(),val.end());
    for(int i = 0; i < n; i++){
        if(m >= val[i]) m -= val[i],ans++;
        else break;
    }

    if(m >= k) ans += m / k;
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