/*https://codeforces.com/problemset/problem/2129/A*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int n;
vector<int> l, r, dsu;

int Find(int x){
    while(dsu[x] != x) x = dsu[x];
    return x;
}


void solve(){
    cin >> n;
    dsu.clear();dsu.resize(2 * n + 1);
    l.assign(2 * n + 1, 0);r.assign(2 * n + 1 ,0);
    for(int i = 1; i <= 2 * n; i++) dsu[i] = i;
    
    for(int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
    }

    vector<int> ans;

    for(int i = 1;i <= n; i++){
        int u = l[i],v = r[i];
        int fx = Find(u),fy = Find(v);

        if(fx != fy){
            dsu[fx] = fy;
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for(auto it : ans) cout << it << " ";
    cout << endl;
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
