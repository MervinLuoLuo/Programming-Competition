/*https://qoj.ac/contest/1862/problem/9667*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int n,m;
vector<vector<char>> g;

bool checker(int x,int y){
    if(x - 1 >= 1 && y + 1 <= m && g[x - 1][y] == 'D' && g[x][y + 1] == 'L'){
        if(x + 1 <= n && y - 1 >= 1 && (g[x + 1][y] == 'U' || g[x][y - 1] == 'R')) return 0;
        return 1;
    }

    if(x - 1 >= 1 && y - 1 >= 1 && g[x - 1][y] == 'D' && g[x][y - 1] == 'R'){
        if(x + 1 <= n && y + 1 <= m && (g[x + 1][y] == 'U' || g[x][y + 1] == 'L')) return 0;
        return 1;
    }

    if(x + 1 <= n && y - 1 >= 1 && g[x + 1][y] == 'U' && g[x][y - 1] == 'R'){
        if(x - 1 >= 1 && y + 1 <= m && (g[x - 1][y] == 'D' && g[x][y + 1] == 'L')) return 0;
        return 1;
    }

    if(x + 1 <= n && y + 1 <= m && g[x + 1][y] == 'U' && g[x][y + 1] == 'L'){
        
    }
}

void solve(){
    cin >> n >> m;
    g.assign(n + 1,vector<char>(m + 1, '0'));
    int cnt = 0;
    vector<PII> C;
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        s = " " + s;
        for(int j = 1; j <= m; j++){
            g[i][j] = s[j];
            if(s[j] == 'C'){
                C.push_back({i,j});
            }
            if(s[j] == '.') cnt++;
        }
    }

    if(cnt != 1 || g[1][m] != '.'){
        cout << "No" << endl;
        return;
    }

    if(n * m == 3 * C.size() + 1){
        cout << "No" << endl;
        return;
    }

    for(auto [x,y] : C){
        if(!checker(x,y)){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}