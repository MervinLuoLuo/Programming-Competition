#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;

void solve(){
    int n,x,y;cin >> n >> x >> y;
    map<int,int> freq;
    for(int i = 0; i < n; i++){
        int m;cin >> m;
        freq[m]++;
    }
    int cnt0 = freq[0];
    vector<pii> a;
    int base = -1;
    for(auto it : freq) {
        a.push_back(it);
        if(it.second > base) base = it.second;
    }
    int ans = (n - base) * y;
    int cntr = 0;
    for(int i = 0; i < (int)a.size(); i++){
        if(a[i].first == 0) continue;
        int num = a[i].first;
        cntr += a[i].second;
        int cost1 = num * x;
        int cost2 = (n - (cnt0 + cntr)) * y;
        // cout << num << " " << cntr << " " << cost1 << " " << cost2 << endl;
        int res = cost1 + cost2;
        ans = min(res,ans);
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}