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
    int n;cin >> n;
    map<int,int> freq;
    int mxsize = 0;
    for(int i = 0; i < n; i ++){
        int x;cin >> x;
        freq[x]++;
        mxsize = max(mxsize,freq[x]);
    }
    int ans = 0;
    for(int i = mxsize; i > 0; i--){
        int cnt = 0;
        for(auto &[u,v] : freq){
            if(v >= i) cnt++;
        } 
        ans = max(ans,i * cnt);
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}