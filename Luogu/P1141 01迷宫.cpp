/*https://www.luogu.com.cn/problem/P1141*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n;
vector<vector<int>> g;
vector<int> p,h;

int find(int x){
    if(p[x] == x) return x;
    else return p[x] = find(x);
}

void Union(int x,int y){
    int px = find(x),py = find(y);
    if(px != py) h[px] += p[py],p[py] = p[px];
}

void solve(){
    int q;cin >> n >> q;
    g.assign(n + 5,vector<int>(n + 5,0));
    p.resize(n + 5);h.assign(n + 5, 1);
    for(int i = 1; i <= n; i++){
        p[i] = i;
    }

    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        s = " " + s;
        for(int j = 1; j <= n; j++){
            g[i][j] = s[j] - '0';
        }
    }
    while(q--){
        int x,y;cin >> x >> y;

    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
