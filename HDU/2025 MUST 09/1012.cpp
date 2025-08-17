#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,m;cin >> n >> m;
    unordered_map<int,int> mp;
    vector<int> times;
    for(int i = 0; i < m; i++){
        int x;cin >> x;
        if(mp[x] == 0) times.push_back(x);
        mp[x]++;
    }
    vector<pii> real;
    for(auto it : mp) real.push_back(it);
    int ans = 0;
    sort(real.begin(),real.end(),[](pii a,pii b){
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    });
    for(int i = 0; i < real.size(); i++){
        if(times[i] != real[i].first) ans++;
    }
    cout << ans <<endl;
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