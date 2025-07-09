/*https://www.luogu.com.cn/problem/P1443*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n,m,x,y;
vector<vector<int>> dist;
queue<pii> q;
int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={2,1,-1,-2,2,1,-1,-2};

void bfs(int x,int y){
    q.push({x,y});
    while(!q.empty()){
        int curx = q.front().first,cury = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++){
            int newx = curx + dx[i],newy = cury + dy[i];
            if(newx <= 0 || newy <= 0 || newx > n || newy > m) continue;
            if(dist[newx][newy] != -1) continue;
            dist[newx][newy] = dist[curx][cury] + 1;
            q.push({newx,newy});
        }
    }

}
void solve(){
    cin >> n>> m >> x >> y;
    dist.resize(n + 5,vector<int>(m + 5 ,-1));
    dist[x][y] = 0;
    bfs(x,y);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cout << dist[i][j] << " ";
        cout << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}