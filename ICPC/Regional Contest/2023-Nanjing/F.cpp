#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,m;cin >> n >> m;
    vector<unordered_set<int>> op(n + 1);
    vector<int> last(m + 1, 0), flag(n + 1, 0);
    for(int i = 1; i <= n; i++){
        int p;cin >> p;
        for(int j = 1; j <= p; j++){
            int b;cin >> b;
            last[b] = i;
            op[i].insert(b);
        }
    }

    for(int i = 1; i <= m; i++){
        if(last[i] > 1 && op[last[i] - 1].count(i)) flag[last[i]] = 1;
    }

    int ans = 0;
    for(int i = 2; i <= n; i++){
        if(!flag[i]) {ans = i;break;}
    }

    if(ans == 0){no;return;}
    yes;
    for(int i = 1; i <= n; i++){
        if(i == ans - 1) cout << ans;
        else if(i == ans) cout << ans - 1;
        else cout << i;
        if(i == n) cout << endl;
        else cout << " ";
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}