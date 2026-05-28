#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e9;

void solve(){
    int n, m, x, y;cin >> n >> m >> x >> y;
    int p = n * m - 1;
    string res = "";
 
    vector<vector<char>> g(n + 1, vector<char>(m + 1));
    auto nxt = [&](){
        if(g[x][y] == 'U'){
            x--;
            res += 'U';
        }else if(g[x][y] == 'L'){
            y--;
            res += 'L';
        }else if(g[x][y] == 'R'){
            y++;
            res += 'R';
        }else{
            x++;
            res += 'D';
        }
    };
    if(m % 2 == 0){
        for(int i = 1; i < n; i++){
            g[i][1] = 'D';
        }
        g[n][1] = 'R';
 
        for(int i = 2; i <= n; i++){
            g[i][m] = 'U';
        }
        g[1][m] = 'L';
 
        for(int i = 2; i < m; i++){
            g[n][i] = 'R';
            if(i % 2 == 0){
                for(int j = 2; j < n; j++){
                    g[j][i] = 'U';
                }
                g[1][i] = 'L';
            }else{
                for(int j = 1; j < n - 1; j++){
                    g[j][i] = 'D';
                }
                g[n - 1][i] = 'L';
            }
        }
        while(p--){
            int a, b;cin >> a >> b;
            while(!(x == a && y == b)){
                nxt();
            }
            cout << res << endl;
            res = "";
        }
 
    }else if(n % 2 == 0){
        for(int i = 1; i < m; i++){
            g[1][i] = 'R';
        }
        g[1][m] = 'D';
 
        for(int i = m; i >= 2; i--){
            g[n][i] = 'L';
        }
        g[n][1] = 'U';
 
        for(int i = 2; i < n; i++){
            g[i][m] = 'D';
            if(i % 2 == 0){
                for(int j = 2; j < m; j++){
                    g[i][j] = 'L';
                }
                g[i][1] = 'U';
            }else{
                for(int j = 1; j < m - 1; j++){
                    g[i][j] = 'R';
                }
                g[i][m - 1] = 'U';
            }
        }
        while(p--){
            int a, b;cin >> a >> b;
            while(x != a || y != b){
                nxt();
            }
            cout << res << endl;
            res = "";
        }
    }
    else{
        for(int i = 1; i < m; i++){
            g[1][i] = 'R';
        }
        for(int i = 2; i <= n; i++){
            g[i][1] = 'U';
        }
        for(int i = 2; i <= m - 2; i++){
            if(i % 2 == 0){
                for(int j = 2; j < n; j++){
                    g[j][i] = 'D';
                }
                g[n][i] = 'L';
            }
            else{
                for(int j = 3; j <= n; j++){
                    g[j][i] = 'U';
                }
                g[2][i] = 'L';
 
            }
        }
        for(int i = 1; i < n; i++){
            if(i & 1){
                g[i][m - 1] = 'R';
                g[i][m] = 'D';
            }
            else{
                g[i][m - 1] = 'D';
                g[i][m] = 'L';
            }
        }
        g[n][m - 1] = 'L';
        g[n][m] = 'L';

        while(p--){
            int a, b;cin >> a >> b;
            if(a == n && b == m){
                g[n - 1][m] = 'D';
            }
            else if(a == n - 1 && b == m - 1){
                g[n - 1][m] = 'L';
            }

            while(x != a || y != b){
                nxt();
            }
            cout << res << endl;
            res = "";
        }
    }
}

signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}