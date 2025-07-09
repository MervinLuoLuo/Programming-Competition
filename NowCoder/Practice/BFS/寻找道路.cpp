/*https://ac.nowcoder.com/acm/problem/16498*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int n, m , s, t;
struct Node{
    vector<int> next, prev;
    bool vis = 0;
    bool visout = 0;
    bool skip = 0;
    int dis = -1;
};

bool check(vector<Node> &node, int idx){
    if(!node[idx].visout) return 1;
    for(auto p : node[idx].next){
        if(node[p].visout == 0) return 1;
    }
    return 0;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<Node> node(n + 5);
    for(int i = 0; i < m; i++){
        int u ,v;cin >> u >> v;
        node[u].next.push_back(v);
        node[v].prev.push_back(u);
    }
    cin >> s >> t;
    queue<int> q;
    q.push(t);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        node[cur].visout = 1;
        for(auto p : node[cur].prev){
            if(node[p].visout == 0) {node[p].visout = 1;q.push(p);}
        }
    }
    for(int i = 0; i <= n; i++){
        node[i].skip = check(node, i);
    }
    queue<int> Q;
    if(!node[s].skip){
        Q.push(s);
        node[s].dis = 0;
        }
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        node[cur].vis = 1;
        for(auto p : node[cur].next){
            if(node[p].skip or node[p].vis) continue;
            node[p].vis = 1;
            node[p].dis = node[cur].dis + 1;
            Q.push(p);
        }
    }
    cout << node[t].dis << endl;
    return 0;
}