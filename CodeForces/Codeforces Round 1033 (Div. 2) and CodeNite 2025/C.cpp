#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,m;cin >> n >> m;
    if((1 + n) * n / 2 < m || n > m){cout << -1 << endl;return;}
    int sum = n;m -= n;
    vector<int> ans;
    int curr = 0, curs = 0;
    for(int i = n - 1; i >= 0; i--){
        if(curr == m) break;
        if(curr + i <= m){
            curr += i;
            ans.push_back(i + 1);
            curs += i + 1;
        }
    }
    for(int i = 0 ; i < n - ans.size(); i++) ans.push_back(1);
    curs += n - ans.size();

    if(m == 0){
        cout << 1 << endl;
        for(int i = 1; i < n; i++) cout << i << " " << i + 1 << endl;
        return;
    }

    vector<bool> vis(n + 1, 1);
    cout << ans[0] << endl;
    vis[ans[0]] = 0;

    for(int i = 1; i <= n; i++){
        cout << ans[i - 1]  << " " << ans[i] << endl;
        vis[ans[i - 1]] = 0,vis[ans[i]] = 0;

        if(ans[i] == 1){
            int pre = 1;
            for(int j = 2; j <= n ;j ++){
                if(vis[j]){cout << pre << " " << j << endl;pre = j;}
            }
            return;
        }
    }

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