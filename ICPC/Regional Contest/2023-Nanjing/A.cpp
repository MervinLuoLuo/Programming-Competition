#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n,m,ans;
vector<string> g;
vector<int> vis;

int dx[4] = {0,-1,1,0};
int dy[4] = {1,0,0,-1};

int pack(int u,int l,int r,int d){
    return u * m * n * m + l * m * n + r * m + d;
}   

void unpack(int val,int &u,int &l,int &r,int &d){
    u = val / (m * n * m);
    l = val / (m * n) % m;
    r = val / m % n;
    d = val % m;
}

bool fall(int x, int y){
    if(x < 1 || y < 1 || x > n || y > m) return 1;
    return 0;
}

void bfs(int x){
    queue<int> q;
    q.push(x);vis[x] = 1;
    while(!q.empty()){
        int u,l,r,d; unpack(q.front(),u,l,r,d);
        for(int k = 0; k < 4; k++){
            int nu = u + dx[k], ll = l + dy[k];
            
        }
    }
}

void solve(){
    cin >> n >> m;
    g.clear();g.resize(n + 1);
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        s = " " + s;
        g[i] = s;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}