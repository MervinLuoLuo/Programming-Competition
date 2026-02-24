#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int m,n,z;cin >> m >> n >> z;
    int add = m + n;
    if(z < m + n){
        if(z > m) cout << 1;
        else cout << 0;
        return;
    }
    int res = z % add;
    if(res == 0) cout << 1;
    else{
        if(res > m) cout << 1;
        else cout << 0;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}