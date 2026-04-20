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
    vector<PII> a(n);
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        a[i] = {x,i + 1};
    }
    sort(a.begin(),a.end(),[](PII x,PII y){
        if(x.first == y.first) return x.second < y.second;
        return x.first < y.first;
    });

    vector<int> ans;
    ans.push_back(a[n - 1].second);
    for(int i = n - 2; i >= 0; i--){
        if(a[i].first != a[n - 1].first) break;
        else ans.push_back(a[i].second);
    }
    sort(ans.begin(),ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if(i != ans.size() - 1) cout << " ";
    }
    cout << endl;

    vector<int> v(n),idx(n);
    for(int i = 0; i < n; i++){
        v[i] = a[i].first;
        idx[i] = a[i].second;
    }

    int q;cin >> q;
    while(q--){
        int x;cin >> x;
        auto p = upper_bound(v.begin(),v.end(),x);
        int pos = 0;
        if(p != v.end()) {
            pos = p - v.begin();
            cout << idx[pos];
        }
        else cout << 0;
        if(q != 0) cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}