#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1, 0),b;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int maxx = *max_element(a.begin() + 1,a.end());
    int minx = *min_element(a.begin() + 1,a.end());
    b = a;
    sort(b.begin() + 1,b.end());

    if(is_sorted(a.begin() + 1,a.end())){
        cout << -1 << endl;
        return;
    }

    int ans = INF;
    bool flag = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] != b[i]){
            int diff = max(a[i] - minx,maxx - a[i]);
            ans = min(ans,diff);
            flag = 1;
        }
    }

    if(!flag) cout << -1 << endl;
    else cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}