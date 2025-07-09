/*https://www.luogu.com.cn/problem/P1747*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
queue<pii> q;
int n,m;
const int dx[] = {1,1,-1,-1,2,2,-2,-2,2,2,-2,-2};
const int dy[] = {2,-2,2,-2,1,-1,1,-1,2,-2,2,-2};

void bfs(int x,int y, vector<vector<int>> &dist){
    q.push({x,y});
    while(!q.empty()){
        int curx = q.front().first, cury = q.front().second;
        q.pop();
        for(int i = 0; i < 12; i++){
            int newx = curx + dx[i],newy = cury + dy[i];
            if(newx <= 0 || newy <= 0) continue;
            if(dist[newx][newy] != -1) continue;
            if(newx == 1 && newy == 1){
                dist[1][1] = dist[curx][cury] + 1;
                return;
            }
            dist[newx][newy] = dist[curx][cury] + 1;
            q.push({newx,newy});
        }
    }
}

void solve(){
    int x1,y1,x2,y2;cin >> x1 >> y1 >> x2 >> y2;
    n = max(x1,x2), m = max(y1,y2);
    vector<vector<int>> dist1(n + 50,vector<int> (m + 50,-1)),dist2(n + 50,vector<int> (m + 50,-1));
    dist1[x1][y1] = 0;dist2[x2][y2] = 0;
    bfs(x1,y1,dist1);
    cout << dist1[1][1] << endl;
    while(!q.empty()) q.pop();
    bfs(x2,y2,dist2);
    cout << dist2[1][1] << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}