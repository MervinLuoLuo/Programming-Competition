#include<bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int MAXN = 1e8;
const int INF = 1e18;

void solve(){
    int n;cin >> n;
    vii g(n);
    vector<int> deg(n);
    for(int i = 0; i < n - 1; i++){
        int u,v;cin >> u >> v;
        u--;v--;
        g[u].push_back(v);g[v].push_back(u);
        deg[u]++;deg[v]++;
    }

    if(n <= 3) {cout << 0 << endl;return;}

    int c1 = 0;
    for(int i = 0; i < n; i++){
        if(deg[i] == 1) c1++;
    }

    int maxn = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int v : g[i]){
            if(deg[v] == 1) cnt++;
        }
        maxn = max(maxn,cnt);
    }
    int ans = c1 - maxn;
    cout << ans << endl;
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
/*
对于一棵n > 3非空树,通过操作可减少到最小直径为 2
在操作中,我们每次操作可以"减少"整个树的一个叶节点
那么我们需要做的就是尽可能的减少有相同父节点的叶节点
答案就是所有叶节点数减去减少叶节点数
*/