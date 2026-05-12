/*https://qoj.ac/contest/3729/problem/17346*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,x;cin >> n >> x;
    map<int,int> mp;
    for(int i = 1; i <= n; i++){
        int x;cin >> x;
        mp[x]++;
    }

    int ans = 0;
    for(auto &[v,cnt] : mp){
        if(cnt <= x) ans += cnt;
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