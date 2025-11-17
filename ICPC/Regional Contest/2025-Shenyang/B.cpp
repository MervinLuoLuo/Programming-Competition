#include <bits/stdc++.h>
#define endl '\n' 
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;

void solve(){
    int n,m,a,b;cin >> n >> m >> a >> b;
    vii g(n + 2, vector<int>(m + 2, -1));
    int cnt0 = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if(g[i][j] == 0) cnt0++;
        }
    }

    vector<int> freq(n * m + 1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(g[i][j] != 0) freq[g[i][j]]++;
        }
    }
    
    sort(freq.begin() + 1,freq.end(),greater<int>());
    int ans = 0;
    int layer = 1;
    for(int i = 2; i <= n * m; i++){
        if(freq[i] == 0) continue;
        if(freq[i] * a <= freq[i] * b * layer){
            ans += freq[i] * a;
        }
        else{
            ans += freq[i] * b * layer;
            layer++;
        }        
        // cout << ans << endl;
    }
    
    ans += b * layer * cnt0;

    // cout << ans << endl;
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

/*
3
1 2 3 2
0 1
2 2 1 1
1 0
2 3
3 3 5 3
2 4 4
4 1 4
4 4 2

2
3
11
*/