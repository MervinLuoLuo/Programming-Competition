/*https://ac.nowcoder.com/acm/problem/16682*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int n,p;
struct Node{
    int state = 0;
    vector<int> son;
};
vector<Node> node;
vector<int> cur;
vector<vector<int>> ans;

void dfs(int x){
    if(node[x].state == 1) return;
    node[x].state = 1;
    cur.push_back(x);

    for(int i = 0;i < node[x].son.size();i++){
        dfs(node[x].son[i]);
    }
}

void solve(){
    cin >> n >>p;
    node.resize(n + 1);
    for(int i = 0; i < p; i++){
        int u,v;cin >> u >> v;
        node[u].son.push_back(v);
        node[v].son.push_back(u);
    }
    node[1].state = 1;
    dfs(1);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}