/*https://www.luogu.com.cn/problem/SP15436*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<vector<int>> a;
vector<vector<int>> vis;
int n, m;

signed bfs(int x, int y){
    int s = 1;
    queue<pii> q;
    q.push({x,y});
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        vis[curx][cury] = 1;
        q.pop();
        for(int i = 0; i < 4; i++){
            int newx = curx + dx[i];
            int newy = cury + dy[i];
            if(newx >= 0 and newy >= 0 and newx < n and newy < m and a[newx][newy] and !vis[newx][newy]){
                q.push({newx,newy});
                vis[newx][newy] = 1;
                s++;
            }
        }
    }
    return s;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin >> n >> m and n and m){
        a.assign(n,vector<int>(m,0));
        vis.assign(n,vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        map<int,int> freq;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] and !vis[i][j]){
                    freq[bfs(i,j)]++;
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
        for(auto p : freq){
            cout << p.first << ' ' << p .second << endl;
        }
    }
    return 0;
}
/*

*/