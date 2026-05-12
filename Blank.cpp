#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define VII vector<vector<int>>
using namespace std;
int n,m,k;
VII g,vis;


void solve(){
    cin >> n >> m >> k;
    g.assign(n + 5,vector<int>(m + 5, 0));
    vis.assign(n + 5,vector<int>(m + 5, 0));
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        s = " " + s;
        for(int j = 1; j <= m; j++){
            if(s[j] == 'o') g[i][j] = 1;
            // cerr << g[i][j] << " ";
        }
        // cerr << endl;
    }

    vector<int> cnt;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!vis[i][j] && g[i][j] == 1){
                int count = 1;
                vis[i][j] = 1;
                for(int k = i + 1; k <= n; k++){
                    if(vis[k][j] || g[k][j] != 1) break;
                    count++;
                    vis[k][j] = 1;
                    
                }
                cnt.push_back(count);
            }
        }
    }

    sort(cnt.begin(),cnt.end(),greater<int>());
    // cerr << endl;
    // for(int x : cnt) cerr << x << " ";
    int ans = 0;
    for(int x : cnt){
        if(x == 1) continue;
        if(x <= k){
            ans += x - 1;
            k -= x;
        }
        else {
            if(k >= 2){
                ans += k - 1;
                k = 0;
                break;
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    solve();
}