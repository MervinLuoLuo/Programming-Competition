#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;

void solve(){
    int n,q;cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<PII> b(n + 1,{-1,-1});
    bool flag = 1;
    for(int i = 1; i <= q; i++){
        int p,l,r;cin >> p >> l >> r;
        auto &[pl,pr] = b[p];
        if(pl == -1 && pr == -1) pl = l,pr = r;
        else{
            if(r < pl || l > pr){
                flag = 0;
                continue;
            }
            int nl = max(l,pl),nr = min(r,pr);
            pl = nl,pr = nr;
        }
    }

    if(!flag){
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        auto &[l,r] = b[i];
        if(l == -1 && r == -1) continue;
        if(a[i] >= l && a[i] <= r) continue;
        int res = min(abs(a[i] - l),abs(a[i] - r));
        ans += res;
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}