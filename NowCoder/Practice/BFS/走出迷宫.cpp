#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n,m;
int x[] = {0,0,1,-1};
int y[] = {1,-1,0,0};
vector<vector<char>> a;
vector<vector<int>> vis;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    while(cin >> n >> m){
        a.clear();
        vis.clear();
        a.resize(n);
        vis.resize(n);
        for(int i = 0; i < n; i++){
            a[i].resize(m);
            vis[i].resize(m);
        }
        int psx = -1, psy = -1, pex = - 1, pey = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char x;
                cin >> x;
                a[i][j] = x;
                if(x == 'S') {psx = i;psy = j;}
                if(x == 'E') {pex = i;pey = j;}
            }
        }
        queue<pii> q;
        q.push({psx,psy});
        vis[psx][psy] = 1;
        while(!q.empty()){
            pii cur = q.front();
            q.pop();
            int curx = cur.first,cury = cur.second;
            vis[curx][cury] = 1;
            for(int i = 0; i < 4; i++){
                int newx = curx + x[i];
                int newy = cury + y[i];
                if(newx >= n or newy >= m or newx < 0 or newy < 0) continue;
                if(!vis[newx][newy] and a[newx][newy] != '#'){
                    vis[newx][newy] = 1;
                    q.push({newx,newy});
                }
            }
        }
        if(vis[pex][pey]) yes;
        else no;
    }
    return 0;
}