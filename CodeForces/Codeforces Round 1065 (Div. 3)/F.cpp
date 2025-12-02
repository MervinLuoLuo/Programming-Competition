#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1, 0), premin(n + 2,maxn);
    vector<pii> suf(n + 2);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        premin[i] = min(premin[i - 1],a[i]);
    }

    for(int i = n; i >= 1; i--){
        suf[i] = max(suf[i + 1], {a[i], i});
    }

    for(int i = 2; i <= n; i++){
        if(premin[i - 1] > suf[i].first){
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;

    for(int l = 1; l <= n;){
        int r = suf[l].second;
        for(int i = l; i < r; i++) cout << a[i] << " " << a[r] << endl;
        if(l > 1) cout << premin[l - 1] << " " << a[r] << endl;
        l = r + 1;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}