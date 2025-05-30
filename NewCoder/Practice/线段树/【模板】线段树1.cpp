/*https://ac.nowcoder.com/acm/problem/226533*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n;
vector<int> a;
struct Node{
    int data = 0;
};
vector<Node> tree;

void build(int cur,int l,int r){
    if(l == r){
        tree[cur].data = a[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(2 * cur, l, mid);
    build(2 * cur + 1, mid + 1, r);
    tree[cur].data = tree[cur * 2].data + tree[cur * 2 + 1].data;
}

int query(int cur,int l,int r, int ql,int qr){
    if(qr< l || ql > r) return 0;
    if(ql <= l && qr >= r) return tree[cur].data;
    int mid = l + ((r - l) >> 1);
    return query(cur * 2, l, mid, ql, qr) + query(cur * 2 + 1, mid + 1, r,ql,qr);
}

void update(int cur,int l,int r,int idx,int value){
    if(l == r){
        tree[cur].data += value;
        return;
    }

    int mid = l + ((r - l) >> 1);
    if(mid >= idx) update(cur * 2, l, mid,idx,value);
    else update(cur * 2 + 1, mid + 1, r, idx,value);
    tree[cur].data = tree[cur * 2].data + tree[cur * 2 + 1].data;
}

void solve(){
    int q;cin >> n >> q;
    a.resize(n + 5);
    tree.resize(4 * n + 5);
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    while(q--){
        int op;cin >> op;
        if(op == 1){
            int i,k;cin >> i >> k;
            update(1,1,n,i,k);
        }
        else {
            int l,r;cin >> l >> r;
            cout << query(1,1,n,l,r) << endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}