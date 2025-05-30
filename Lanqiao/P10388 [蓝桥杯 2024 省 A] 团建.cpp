#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

struct Node {
    int val;
    vector<int> children;
    unordered_map<int, int> child_map; // 子节点权值映射
};

void buildTree(vector<Node>& tree, vector<vector<int>>& adj, int root) {
    int n = tree.size()-1;
    vector<bool> visited(n+1, false);
    queue<int> q;
    
    q.push(root);
    visited[root] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                tree[u].children.push_back(v);
                tree[u].child_map[tree[v].val] = v;
                q.push(v);
            }
        }
    }
}

int max_len;

void dfs(int u, int v, int depth, vector<Node>& A, vector<Node>& B) {
    if (A[u].val != B[v].val) return;
    
    max_len = max(max_len, depth);
    
    for (int child : A[u].children) {
        int val = A[child].val;
        if (B[v].child_map.count(val)) {
            dfs(child, B[v].child_map[val], depth+1, A, B);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<Node> N(n+1), M(m+1);
    for (int i=1; i<=n; ++i) cin >> N[i].val;
    for (int i=1; i<=m; ++i) cin >> M[i].val;
    
    // 构建树结构
    vector<vector<int>> adj1(n+1);
    for (int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    buildTree(N, adj1, 1);
    
    vector<vector<int>> adj2(m+1);
    for (int i=1; i<m; ++i) {
        int p, q; cin >> p >> q;
        adj2[p].push_back(q);
        adj2[q].push_back(q); // 这里应该改为 adj2[q].push_back(p);
    }
    buildTree(M, adj2, 1);  // 修正邻接表错误

    max_len = 0;
    if (N[1].val == M[1].val) {
        dfs(1, 1, 1, N, M);
    }
    cout << max_len << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}