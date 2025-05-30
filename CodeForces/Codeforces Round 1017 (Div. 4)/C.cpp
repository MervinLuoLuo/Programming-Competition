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
    int n;cin >> n;
    vector<vector<int>> a(n + 1 ,vector<int> (n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
    vector<int> ans(2 * n + 2,0),vis(2 * n + 2,0);
    for(int i = 1; i <= n; i++) {ans[1 + i] = a[1][i];vis[a[1][i]] = 1;}
    for(int i = 1; i <= n; i++) {ans[n + i] = a[i][n]; vis[a[i][n]] = 1;}
    for(int i = 1; i <= 2 * n; i++){
        if(!ans[i]){
            for(int j = 1; j <= n * 2; j++) if(!vis[j]){
                ans[i] = j;
            }
        }
    }
    for(int i = 1; i <= n *2; i++) cout << ans[i] << " ";
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}