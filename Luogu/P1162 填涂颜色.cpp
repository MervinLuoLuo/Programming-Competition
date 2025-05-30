/*https://www.luogu.com.cn/problem/P1162*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int n;
vector<vector<int>> a;
vector<vector<int>> vis;

void bfs(int x, int y){
    vis[x][y] = 1;
    queue<pii> q;
    q.push({x,y});
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int newx = curx + dx[i];
            int newy = cury + dy[i];
            if(newy >= 0 and newx >= 0 and newx < n and newy < n and !vis[newx][newy] and a[newx][newy]){
                vis[newx][newy] = 1;
                q.push({newx,newy});
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    a.assign(n,vector<int>(n,0));
    vis.assign(n,vector<int>(n,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) vis[i][j] = 1;
        }
    }
    `
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!vis[i][j]) cout << 2 << ' ';
            else cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
