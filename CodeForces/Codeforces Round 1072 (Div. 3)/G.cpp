#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
struct NODE{
    int val;
    int lazy = 0;
};
vector<NODE> seg;
vector<int> a;
int n,q;

void build(int cur,int l,int r){
    if(l == r){
        seg[cur].val = a[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * cur, l, mid);
    build(2 * cur + 1,mid + 1, r);
    seg[cur].val = min(seg[2 * cur].val, seg[2 * cur + 1].val);
}

int query(int cur,int l,int r,int ql,int qr){
    if(qr < l || ql > r) return INF;

    if(ql <= l && qr >= r) return seg[cur].val;

    int mid = l + (r - l) / 2;
    int L = query(cur * 2,l,mid,ql,qr);
    int R = query(cur * 2 + 1,mid + 1,r,ql,qr);
    int res = min(L,R);
    return res;
}

void modify(int cur,int l,int r, int pos,int val){
    if(l == r){
        seg[cur].val = val;
        return;
    }

    int mid = l + (r - l) / 2;
    if(pos <= mid) modify(cur * 2,l,mid,pos,val);
    else modify(cur * 2 + 1,mid + 1,r, pos, val);

    seg[cur].val = min(seg[2 * cur].val,seg[2 * cur + 1].val);
}

void solve(){
    cin >> n >> q;
    seg.assign(4 * n, {0,0});
    a.assign(n + 1,0);

    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);

    while(q--){
        int op;cin >> op;
        if(op == 1){
            int pos,x;cin >> pos >> x;
            a[pos] = x;
            modify(1,1,n,pos,x);
        }
        else{
            int l,r;cin >> l >> r;
            int L = 0,R = r - l;
            int tar = -1;

            while(L <= R){
                int mid = L + (R - L) / 2;
                int minv = query(1,1,n,l,l + mid);

                if(minv == mid){
                    tar = mid;
                    break;
                }
                else if(minv > mid) L = mid + 1;
                else R = mid - 1;
            }

            if(tar != -1) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }

    // cout << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}