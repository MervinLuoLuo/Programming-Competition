/*https://www.luogu.com.cn/problem/P1189*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n,m;int o;
vector<vector<int>> a;
vector<string> op;

void dfs(int px,int py,int cnt){
    if(cnt > o){
        a[px][py] = '*';
    }
    
    if(op[cnt + 1] == "NORTH"&& a[px - 1][py] != 'X') dfs(px -1,py,cnt+1);
    else if(op[cnt + 1] == "SOUTH" && a[px + 1][py] != 'X') dfs(px + 1,py,cnt+1);
    else if(op[cnt + 1] == "WEST"&& a[px][py - 1] != 'X') dfs(px,py-1,cnt+1);
    else if(op[cnt + 1] == "EAST"&& a[px][py + 1] != 'X') dfs(px,py + 1,cnt + 1);
    
    
}
void solve(){
    cin >> n >> m;
    a.resize(n + 5,vector<int>(m + 5));
    int px = 0,py = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1; j <=m;j++) {
            cin >> a[i][j];
            if(a[i][j] == '*') px=i,py=j;
        }
    }
    cin >> o;
    op.resize(o);
    for(int i = 0; i < o; i++) cin >> op[i];
    dfs(px,py,0);
    a[px][py] = '.';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}