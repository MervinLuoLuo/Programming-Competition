#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int,int> ls;
    ls.reserve(n * 2);
    for(int i = 0; i < n; i++) ls[a[i]] = i;
    unordered_set<int> ps;
    ps.reserve(n * 2);
    int ans = 0, i = 0;
    while(i < n){
        unordered_set<int> cs;
        cs.reserve(16);
        int uc = ps.size();
        unordered_map<int,bool> hm;
        hm.reserve(ps.size() * 2);
        for(auto x : ps) hm[x] = 0;
        int ml = INF;//前段中所有元素的最后出现位置的最小值,安全分段
        for(int j = i;; j++){
            int v = a[j];
            if(!cs.count(v)){
                cs.insert(v);
                ml = min(ml, ls[v]);
            }
            auto it = hm.find(v);
            if(it != hm.end() && !it->second){it->second = 1;--uc;}
            if(uc == 0 && j < n - 1 && ml > j){ans++;ps = move(cs);i = j + 1;break;}
            if(j == n - 1){ans++;i = n;break;}
        }
    }
    cout << ans << endl;
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