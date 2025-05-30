#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin >> n;
    vector<vector<int>> node(n);
    for(int i = 1; i < n; i++){
        int u, v;cin >> u >> v;
        u--;v--;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    for(int i = 0 ; i < n; i++){
        if(node[i].size() > 2){
            cout << -1 << endl;
            return 0;
        }
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(node[i].size() == 1) ans.push_back(i);
    }
    cout << ans[0] + 1 << ' ' << ans[1] + 1 << endl;
    return 0;
}