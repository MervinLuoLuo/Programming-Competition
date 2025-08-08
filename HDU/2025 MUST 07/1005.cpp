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

struct Point{
    int x;
    int y;
    int r;
};

vector<string> g;

int n,m,k;
void draw(int x,int y,int r){
    g[x][y] = r + '0';
    if(x - 1 >= 0){
        g[x - 1][y] = r + '0';
        if(x - 2 >= 0){
            g[x - 2][y] = r + '0';
            if(y - 1 >= 0) g[x - 2][y - 1] = r + '0';
            if(y - 2 >= 0) g[x - 2][y - 2] = r + '0';
            if(y + 1 < m) g[x - 2][y + 1] = r + '0';
            if(y + 2 < m) g[x - 2][y + 2] = r + '0';
            if(x - 3 >= 0){
                g[x - 3][y] = r + '0';
                if(y - 1 >= 0) g[x - 3][y - 1] = r + '0';
                if(y + 1 < m) g[x - 3][y + 1] = r + '0';
                if(x - 4 >= 0){
                    g[x - 4][y] = r + '0';
                }
            }
        }
    }
}
void solve(){
    cin >> n >> m >> k;
    vector<Point> p(k);
    for(int i = 0; i < k; i++){
        cin >> p[i].x >> p[i].y;
        p[i].x--,p[i].y--;
        p[i].r = i + 1;
    }
    sort(p.begin(),p.end(),[](Point a, Point b){
        return a.x < b.x;
    });
    g.assign(n,string(m,'.'));
    for(Point it : p) draw(it.x,it.y,it.r);

    for(string it : g) cout << it << endl;
    // cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}