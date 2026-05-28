#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
bool sta = 1;
void duip(int n, int k, VII g){
    int ans = INT_MAX;
    bool res = true;
    set<int> ms;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(ms.count(g[i][j])==1){
                res = false;
            }
            ms.insert(g[i][j]);
        }
    }
    for(int i = 1; i <= n; ++i){
        int te = -1;
        for(int j = 1; j <= n; ++j){
            te = max(te, g[i][j]);
        }
        ans = min(ans, te);
    }
    
    for(int i = 1; i <= n; ++i){
        int te = -1;
        for(int j = 1; j <= n; ++j){
            te = max(te, g[j][i]);
        }
        ans = min(ans, te);
    }
    // cerr << "ans : " << ans << endl;
    if(ans == k&&res) int a = 0;
    else{
        cout << "-----------WA" << endl;
        sta = 0;
        cerr << "n : "<< n << " k : " << k << endl; 
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
        cout << "end------------" << endl;
    }
}
void solve(){
    
    
    // int n,k;cin >> n >> k;
    int n = rand() % 50 + 1;
    int k = rand() % (n * n) + 1;
    // cerr << "n : " << n << " k : " << k << endl;
    if(k < n || k > n * n - n + 1){
        // cout << "No" << endl;
        return;
    }
    // cout << "Yes" << endl;
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
        // for(int j = 1; j <= n; j++) cout << g[i][j] << " ";
        // cout << endl;
    }
    if(sta){
        duip(n, k, g);
    }
    
}

signed main(){
    srand(time(0));
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}