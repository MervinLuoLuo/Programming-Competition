/*https://www.luogu.com.cn/problem/solution/P1189*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int r,c;
int n;
vector<vector<char>> g;
vector<string> to;

void dfs(int x, int y, int cur, vector<int> vis) {
    if (cur == n) {
        g[x][y] = '*';
        return;
    }

    if(to[cur] == "NORTH"){
        if(g[x - 1][y] != 'X') {
            auto vis1 = vis;
            vis1[cur] = 1;
            dfs(x - 1, y, cur, vis);
            dfs(x - 1, y, cur + 1, vis1);
        }
        else {
            if(vis[cur]) dfs(x, y, cur + 1, vis);
        }
    }

    if(to[cur] == "SOUTH"){
        if(g[x + 1][y] != 'X'){
            auto vis1 = vis;
            vis1[cur] = 1;
            dfs(x + 1, y, cur, vis);
            dfs(x + 1, y, cur + 1, vis1);
        }
        else {
            if(vis[cur]) dfs(x, y, cur + 1, vis);
        }
    }

    if(to[cur] == "WEST"){
        if(g[x][y - 1] != 'X'){
            auto vis1 = vis;
            vis1[cur] = 1;
            dfs(x, y - 1, cur, vis);
            dfs(x, y - 1, cur + 1, vis1);
        }
        else {
            if(vis[cur]) dfs(x, y, cur + 1, vis);
        }
    }

    if(to[cur] == "EAST"){
        if(g[x][y + 1] != 'X'){
            auto vis1 = vis;
            vis1[cur] = 1;
            dfs(x, y + 1, cur, vis);
            dfs(x, y + 1, cur + 1, vis1);
        }
        else {
            if(vis[cur]) dfs(x, y, cur + 1, vis);
        }
    }
}


void solve(){
    cin >> r >> c;
    int x = -1, y = -1;
    g.assign(r + 5,vector<char>(c + 5,'X'));
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> g[i][j];
            if(g[i][j] == '*') {x = i,y = j;g[i][j] = '.';}
        }
    }
    cin >> n;
    to.assign(n,"");
    vector<int> vis(n,0);
    for(int i = 0; i < n; i++) cin >> to[i];

    dfs(x,y,0,vis);

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++) cout << g[i][j];
        cout << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}