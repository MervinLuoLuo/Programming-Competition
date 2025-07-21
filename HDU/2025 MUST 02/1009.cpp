#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
struct Node{
    int val;
    int lazy = 0;
    int dep = 0;
    int size = 0;    
    int fa = 0;     
    int son = 0;    
    int dfn = 0;    
    int top = 0;    
};
int n,m;
vector<Node> tree;
vector<int> idx;

struct Graph{//邻接表
    vector<vector<int>> table;
    //初始化
    void init(int _n) {
        table.assign(_n + 1, {});
    }
    //加边
    void add_edge(int u, int v) {
        table[u].push_back(v);
    }
}g;

int dfsC= 0;

void dfs1(int cur,int fat){
    tree[cur].dep = tree[fat].dep + 1;
    tree[cur].size = 1;
    tree[cur].fa = fat;
    tree[cur].son = 0;

    for(int v : g.table[cur]){
        if(v == fat) continue;
        dfs1(v,cur);
        tree[cur].size += tree[v].size;
        if(tree[v].size > tree[tree[cur].son].size) tree[cur].son = v;
    }
}

void dfs2(int cur,int top){
    dfsC++;
    tree[cur].dfn = dfsC;
    idx[dfsC] = cur;
    tree[cur].top = top;

    if(tree[cur].son) dfs2(tree[cur].son,top);

    for(int v : g.table[cur]){
        if(v == tree[cur].fa || v == tree[cur].son) continue;
        dfs2(v,v);
    }
}

struct node{
    int max = 0;
};
vector<node> seg;

void build(int cur,int l,int r){
    if(l == r) {seg[cur].max = tree[idx[l]].val;return;}

    int mid = l + ((r - l) >> 1);
    build(2 * cur,l,mid);
    build(2 * cur + 1,mid + 1, r);
    seg[cur].max = max(seg[2 * cur].max, seg[2 * cur + 1].max);
}

void update(int cur,int l,int r,int tar,int val){
    if(l == r) {seg[cur].max += val;return;}
    
    int mid = l + ((r - l) >> 1);

    if(tar <= mid) update (2 * cur,l,mid,tar,val);
    else update(2 * cur + 1,mid + 1, r,tar,val);

    seg[cur].max = max(seg[2 * cur].max,seg[2 * cur + 1].max);
}

int query(int cur,int l,int r,int ql,int qr){
    if(r < ql || l > qr) return 0;
    if(l >= ql && r <= qr) return seg[cur].max;

    int mid = l + ((r - l) >> 1);
    if(ql <= mid && mid < qr) return max(query(2 * cur, l ,mid,ql,qr),query(2 * cur + 1,mid + 1,r,ql,qr));

    if(ql <= mid)return query(2 * cur,l,mid,ql,qr);
    return query(2 * cur + 1,mid + 1, r,ql,qr);
}

int pathq(int x,int y){
    int ans = 0;
    while(tree[x].top != tree[y].top){
        if(tree[tree[x].top].dep > tree[tree[y].top].dep) swap(x,y);

        ans = max(ans,query(1,1,n,tree[tree[y].top].dfn,tree[y].dfn));
        ans = max(ans,tree[tree[y].top].val + tree[tree[tree[y].top].fa].lazy);
        y = tree[tree[y].top].fa;
    }

    if(tree[x].dep > tree[y].dep) swap(x,y);

    ans = max(ans,query(1,1,n,tree[x].dfn,tree[y].dfn));
    if(x == tree[x].top) ans = max(ans,tree[x].val + tree[tree[x].fa].lazy);
    return ans;
}

void change(int x,int z){
    if(tree[x].fa){
        update(1,1,n,tree[tree[x].fa].dfn,z);
        tree[tree[x].fa].val += z;
    }

    if(tree[x].son){
        update(1,1,n,tree[tree[x].son].dfn,z);
    }
    tree[x].lazy += z;
}

void solve(){
    cin >> n >> m;
    tree.assign(n + 1,{});
    idx.assign(n + 1,{});
    seg.clear();seg.resize(n * 4 + 5);
    g.init(n);

    for(int i = 1; i <= n; i++){
        cin >> tree[i].val;
        tree[i].lazy = 0;
    }

    for(int i = 1; i < n; i++){
        int u,v;cin >> u >> v;
        g.add_edge(u,v);
        g.add_edge(v,u);
    }

    dfsC = 0;
    dfs1(1, 0);
    dfs2(1, 1);
    build(1,1,n);

    while(m--){
        int op;cin >> op;
        if(op == 1){
            int x,y;cin >> x >> y;
            cout << pathq(x,y) << endl;
        }
        else{
            int x,z;cin >> x >> z;
            change(x,z);
        }
    }
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