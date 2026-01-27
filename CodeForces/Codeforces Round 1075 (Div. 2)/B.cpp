#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,x;cin >> n >> x;
    int m = 0,gain = 0;

    for(int i = 0; i < n; i++){
        int a,b,c;cin >> a >> b >> c;
        m += (b - 1) * a;
        int g = b * a - c;
        gain = max(gain,g);
    }

    if(m >= x) {cout << 0 << endl;return;}
    if(gain <= 0){cout << -1 << endl;return;}
    int need = x - m;
    int ans = (need + gain - 1) / gain;
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