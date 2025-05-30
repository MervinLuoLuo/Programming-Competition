#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
typedef long long ll;

void solve(){
    int n, m;cin >> n >> m;
    map<pii,int> freq;
    int ans = 0;
    for(int i = 0; i < m; i++){
        int u ,v;cin >> u >> v;
        if(u == v){ans++;continue;}
        if(u > v){swap(u,v);}
        freq[{u,v}]++; 
    }
    for(auto it : freq){
        ans += it.second - 1;
    }
    cout << ans << endl;
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