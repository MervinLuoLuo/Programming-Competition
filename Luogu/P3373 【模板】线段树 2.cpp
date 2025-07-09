/*https://www.luogu.com.cn/problem/P3373*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n,q,m;
vector<int> a;
class Node{
    public:
    int val;
    int addl = 0;
    int mull = 1;
};
vector<Node> seg;

void build(int cur,int l,int r){
    if(l == r){
        seg[cur].val = a[l] % m;
        return;
    }

    int mid = l + ((r - l) >> 1);
    build(2 * cur,l ,mid);
    build(2 * cur + 1, mid + 1, r);

    seg[cur].val = (seg[2 * cur].val + seg[2 * cur + 1] .val) % m;
}

void pushDown(int cur,int l,int r){
    int mid = l + ((r - l) >> 1);
    //Left
    seg[2 * cur].val = (seg[cur].mull * seg[2 * cur].val % m + seg[cur].addl * (mid - l + 1) % m) % m;
    seg[2 * cur].mull = seg[cur].mull * seg[2 * cur].mull % m;
    seg[2 * cur].addl = (seg[2 * cur].addl * seg[cur].mull % m +seg[cur].addl) % m;
    //Right
    seg[2*cur + 1].val = (seg[2 * cur + 1].val * seg[cur].mull % m + seg[cur].addl * (r - mid) % m) % m;
    seg[2 * cur + 1].mull = seg[2 * cur + 1].mull * seg[cur].mull % m;
    seg[2 * cur + 1].addl = (seg[2 * cur + 1].addl * seg[cur].mull % m + seg[cur].addl) % m;

    seg[cur].addl = 0;seg[cur].mull = 1;
}

int query(int cur,int l,int r,int ql,int qr){
    if(ql > r || qr < l) return 0;

    if(ql <= l && qr >= r) return seg[cur].val;

    int mid = l + ((r - l) >> 1);
    pushDown(cur, l, r);

    int sum = 0;
    if(ql <= mid) sum = (sum + query(2 * cur,l,mid,ql,qr)) % m; 
    if(qr > mid) sum = (sum + query(2 * cur + 1,mid + 1, r,ql,qr)) % m;

    return sum % m;
}

void updatem(int cur,int l,int r,int ul,int ur,int val){
    if(ul <= l && ur >= r){
        seg[cur].val = val * seg[cur].val % m;
        seg[cur].mull = seg[cur].mull * val % m;
        seg[cur].addl = seg[cur].addl * val % m;
        return;
    }
    pushDown(cur,l,r);

    int mid = l + ((r - l) >> 1);
    if(ul <= mid) updatem(2 * cur,l,mid,ul,ur,val);
    if(ur > mid) updatem(2 * cur + 1,mid + 1,r,ul,ur,val);

    seg[cur].val = (seg[2 * cur].val + seg[2*cur + 1].val) % m;
}

void updatea(int cur,int l,int r,int ul,int ur,int val){
    if(ul <= l && ur >= r){
        seg[cur].val = (seg[cur].val + val *(r - l + 1) % m) % m;
        seg[cur].addl = (seg[cur].addl + val) % m;
        return;
    }
    pushDown(cur,l,r);

    int mid = l + ((r - l) >> 1);
    if(ul <= mid) updatea(cur,l,mid,ul,ur,val);
    if(ur > mid) updatea(cur,mid + 1, r,ul,ur,val);

    seg[cur].val = (seg[2 * cur].val + seg[2 * cur + 1].val) % m;
}

void solve(){
    cin >> n >> q >> m;
    seg.resize(n * 4 + 5);
    a.resize(n + 5);
    for(int i = 1; i <= n; i++) {cin >> a[i]; a[i] %= m;}
    build(1,1,n);
    for(int i = 0; i < q; i++){
        int op,x,y;cin >> op >> x >> y;
        if(op == 1){
            int k;cin >> k;
            updatem(1,1,n,x,y,k);
        }
        else if(op == 2){
            int k;cin >> k;
            updatea(1,1,n,x,y,k);
        }
        else cout << query(1,1,n,x,y) << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}