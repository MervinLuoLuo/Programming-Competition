#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
// #define DBG
#ifdef DBG
    #define dbg(x) cerr << #x << " = " << x << endl;
#else
    #define dbg(x)
#endif
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,m,u;cin >> n >> m >> u;
    vector<int> a(n + 1),b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    int ans = 0;
    for(int l = 1; l <= n; l++){
        int r = l;
        int cur = 0,dura = m;
        while(r <= n && dura - a[r] >= 0 && cur + b[r] <= u){
            dura -= a[r];cur += b[r];
            r++;
        }
        int len = r - l;
        dbg(len);
        ans = max(ans, len);
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}