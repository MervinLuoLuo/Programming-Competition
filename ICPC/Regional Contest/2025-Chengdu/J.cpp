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
    int n,m,k,b;cin >> n >> m >> k >> b;
    int ans = 0,cnt = 0;
    for(int i = 1; i <= n; i++){
        int res = 0,rej = 0;
        
        for(int j = 1; j <= m; j++){
            int x;cin >> x;
            res += x;
            if(x <= 0) rej++;
            else if(x >= 1) rej--;
        }
        if(res >= k) ans++;
        else{
            if(res + rej >= k) cnt++;
        }
    }
    ans += min(b,cnt);
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