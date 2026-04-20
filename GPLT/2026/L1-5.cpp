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
    map<int,int> mp;
    for(int i = 1; i <= n; i++){
        int x,y;cin >> x >> y;
        if(y == 1) mp[x] = 1;
        else{
            if(mp.count(x) == 0) mp[x] = 0;
        }
    }

    vector<int> ans;
    for(auto [x,y] : mp){
        if(y == 0) ans.push_back(x);
    }
    if(ans.size() == 0) cout << "NONE";
    else{
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i];
            if(i != ans.size() - 1) cout << " ";
        }
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