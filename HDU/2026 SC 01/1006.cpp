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
    unordered_map<int,int> mp;
    int ans = n;
    for(int i = 1; i <= n; i++){
        int x;cin >> x;
        if(x > n || x < 1) {
            ans--;
            continue;
        }
        mp[x]++;
        if(mp[x] > 1) ans--;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}