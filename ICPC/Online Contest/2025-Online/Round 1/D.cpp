#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define vii vector<vector<int>>
const int INF = 1e18;
const int MAXN = 1e8;

void solve(){
    int n,m;cin >> n >> m;
    vector<int> v(n + 1);
    for(int i = 0; i < m; i++){
        int a,b;cin >> a >> b;
        if(a + 1 == b) v[a] = 1;
    }
    
    for(int i = 1; i <= n - 1; i++){
        if(v[i] != 1){cout << "No" << endl;return;}
    }
    cout << "Yes" << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}