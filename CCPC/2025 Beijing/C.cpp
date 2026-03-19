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

bool check(int n,int m,int x){
    int res = 0;
    for(int i = 0; i < m; i++){
        int w = min(x,res + 1);
        res += w;
        if(res >= n) return 1;
        if(res > 4e18) return 1;
    }
    return res >= n;
}

void solve(){
    int n,m;cin >> n >> m;
    if(m <= 30){
        int maxx = (1ll << m) - 1;
        if(n > maxx) {cout << -1 << endl;return;}
    }
    int l = 1,r = n, ans = n;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(n,m,mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
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