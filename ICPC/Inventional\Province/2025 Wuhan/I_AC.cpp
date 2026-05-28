#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;

void solve(){
    int n,k;cin >> n >> k;
    if(k < n || k > n * n - n + 1){
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    VII g(n + 1,vector<int>(n + 1, 0));

    int cur = 1;
    int x = 0,y = 0;
    for(int i = 1;  i<= n; i++){
        for(int j = 1; j <= n; j++){
            g[i][j] = cur;
            cur++;
        }
    }

    int c = n;
    for(int i = 1; i <= n; i++){
        swap(g[i][c],g[n][c]);
        c--;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(g[i][j] == k) swap(g[i][j],g[1][n]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << g[i][j] << " ";
        cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}