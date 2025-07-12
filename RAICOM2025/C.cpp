#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
#define pii pair<int,int>
#define b cout<<"B"<<endl
#define a cout<<"A"<<endl
using namespace std;
const int maxn = 1e9;
// const int INF = 1e19;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

struct Node{
    int link[4];
};

void solve(){
    int n,m,s;cin >> n >> m >> s;
    vector<vector<Node>> g(n + 5,vector<Node>(m + 5));
    int hand = 0;
    int as = 0,bs = 0,pcnt = 0;
    for(int step = 0; step < s; step++){
        int op,sx,sy,ex,ey;cin >> op >> sx >> sy >> ex >> ey;
        if(op != hand){pcnt++;continue;}
        bool get = 0;
        if(ex == sx + 1 && ey == sy){
            g[sx][sy].link[0] = 1;
            g[ex][ey].link[2] = 1;
            int x = min(sx,ex),y = sy;
        }
        else if(ex == sx && ey == sy + 1){
            g[sx][sy].link[1] = 1;
            g[ex][ey].link[3] = 1;
        }
        else if(ex == sx - 1 && ey == sy){
            g[sx][sy].link[3] = 1;
            g[ex][ey].link[0] = 1;
        }
        else{
            g[sx][sy].link[3] = 1;
            g[ex][ey].link[1] = 1;
        }
    }    
}

signed main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}