#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,m;cin >> n >> m;
    vector<vector<int>> a(n + 1,vector<int> (m + 1,INF));
    map<int,int> b,c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x;cin >> x;
            b[i + j] += x;
            c[i - j] += x;
            a[i][j] = x;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int cur = b[i + j] + c[i - j] - a[i][j];
            ans = max(ans,cur);
        }
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}