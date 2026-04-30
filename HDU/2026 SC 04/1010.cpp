/*https://acm.hdu.edu.cn/contest/problem?cid=1200&pid=1010*/
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
    int n,m;cin >> n >> m;
    VII a(n + 1,vector<int>(m + 1,-1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }
    int pre = *min_element(a[1].begin() + 1,a[1].end());

    for(int i = 2; i <= n; i++){
        sort(a[i].begin() + 1,a[i].end());
        auto p = upper_bound(a[i].begin() + 1,a[i].end(),pre);
        // cerr << i << " " << pre << endl;
        if(p == a[i].end()){
            cout << "NO" << endl;
            return;
        }
        int cur = *p;
        pre = cur;
    }
    cout << "YES" << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}