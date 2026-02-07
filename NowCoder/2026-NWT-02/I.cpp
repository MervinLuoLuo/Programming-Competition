#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void solve(){
    int n,m;cin >> n >> m;
    vector<string> g(n + 1,"");
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        s = " " + s;
        g[i] = s;
    }

    VII vis(n + 1,vector<int>(m + 1, 0));
    vector<string> ans(n + 1,string(m + 1,'N'));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!vis[i][j]){
                vector<PII> com;
                queue<PII> q;
                q.push({i,j});
                vis[i][j] = 1;
                int cnt0 = 0,cnt1 = 0;
                
                while(!q.empty()){
                    auto &[ci,cj] = q.front();
                    q.pop();
                    com.push_back({ci,cj});
                    if(g[ci][cj] == '0') cnt0++;
                    else cnt1++;

                    for(int k = 0; k < 4; k++){
                        int ni = ci + dx[k],nj = cj + dy[k];
                        if(ni >= 1 && ni <= n && nj >= 1 && nj <= m && !vis[ni][nj]){
                            vis[ni][nj] = 1;
                            q.push({ni,nj});
                        }
                    }
                }
                for(auto &[ci,cj] : com){
                    if(g[ci][cj] == '0'){
                        if(cnt0 > 1) ans[ci][cj] = 'Y';
                    }
                    else{
                        if(cnt1 > 1) ans[ci][cj] = 'Y';
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cout << ans[i][j];
        cout << endl;
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