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

void solve(){
    VII g(n + 5,vector<int>(m + 5, 0));
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        s = " " + s;
        for(int j = 1; j <= m; j++){
            if(s[j] == 'o') g[i][j] = 1;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(g[i][j] == 1){
                bool flag = 1;
                int ni = i;
                while(ni <= n && g[ni][j] == 1){
                    if(g[ni][j - 1] == 1 || g[ni][j + 1] == 1){
                        flag = 0;break;
                    }
                    ni++;
                }
                if(flag){
                    cout << "2018\n";
                    return;
                }
            }
        }
    }
    cout << "2020\n";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin >> n >> m)
    solve();
    return 0;
}