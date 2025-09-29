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
int n,m;
vii g;
int ans = maxn;

int dy[] = {1,1,0};
int dx[] = {1,0,1};
void dfs(int x,int y,int cnt){
    if(x == n - 1 && y == m){
        ans = min(ans,cnt);
        return;
    }

    bool flag = 1;
    for(int i = 0; i < 3; i++){
        
    }
}
void solve(){
    cin >> n >> m;
    g.assign(n + 2,vector<int> (m + 2, 0));
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        s = " " + s;
        for(int j = 1; j <= m; j++){
            if(s[j] == '#') g[i][j] = 0;
            else g[i][j] = 1;
        }
    }


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