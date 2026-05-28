#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define VII vector<vector<int>>
using namespace std;
constexpr int dx[] = {0,0,1,-1};
constexpr int dy[] = {1,-1,0,0};

int n,m,h;
VII g,best;
int sx,sy,ex,ey;

void bfs(){
    queue<tuple<int,int,int>> q;
    best[sx][sy] = h;
    q.push({sx,sy,h});

    while(!q.empty()){
        auto [x,y,ch] = q.front();
        q.pop();
        
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k],ny = y + dy[k];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            int nh = ch - g[nx][ny];
            if(nh <= 0 || nh <= best[nx][ny]) continue;
            best[nx][ny] = nh;
            q.push({nx,ny,nh});
        }
    }
}

void solve(){
    cin >> n >> m >> h;
    g.assign(n + 1,vector<int>(m + 1, 0));
    best.assign(n + 1,vector<int>(m + 1, -1));
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        s = " " + s;
        for(int j = 1; j <= m; j++){
            if(s[j] == 'S'){
                sx = i,sy = j;
                g[i][j] = 0;
            }
            else if(s[j] == 'T'){
                ex = i,ey = j;
                g[i][j] = 0;
            }
            else{
                g[i][j] = s[j] - '0';
            }
        }
    }

    bfs();
    if(best[ex][ey] > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}