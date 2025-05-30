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
    
    int n;cin >> n;
    vector<int> a(n + 5);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1;
    vector<pii> ans;
    unordered_map<int,int> cnt;
    cnt[a[1]]++;
    for(int r = 2; r <= n; r++){
        int cur = a[r];
        cnt[cur]++;
        while(l < r and cnt[cur] > 2){
            cnt[a[l]]--;
            l++;
        }
        if(r - l != 1  and r - l != 0)ans.push_back({l,r});
    }
    cout << ans.size() << endl;
    for(auto it : ans) cout << it.first << ' ' << it.second << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}