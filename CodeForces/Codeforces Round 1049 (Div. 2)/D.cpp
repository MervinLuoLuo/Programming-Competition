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

bool cmpl(const pii &a,const pii &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

bool cmpr(const pii &a, const pii &b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

void solve(){
    int n;cin >> n;
    vector<pii> L(n), R(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int l,r;cin >> l >> r;
        L[i] = {l,i}; R[i] = {r,i};
        ans += r - l;
    }

    sort(L.begin(),L.end(),cmpl);
    sort(R.begin(),R.end(),cmpr);

    vector<int> vis(n,0);
    int l = 0, r = 0;
    while(R[r].first >= L[l].first){
        if(vis[l]) {l++;continue;}
        if(vis[r]) {r++;continue;}
        // if(R[r].first < L[l].first) break;
        if(L[l].second == R[l].second){
            
        }
        
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