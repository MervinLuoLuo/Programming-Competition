/*https://www.luogu.com.cn/problem/P3372*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n,m;

class Node{
    public:
    int val;
    int lazy = 0;
};
vector<Node> seg;
vector<int> a;

void build(int cur,int l,int r){
    if(l == r){
        seg[cur].val = a[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(2 * cur,l,mid);
    build(2*cur + 1,mid + 1, r);
    seg[cur].val = seg[2*cur].val + seg[2*cur + 1].val;
}

void pushDown(int cur,int l,int r){
    if(seg[cur].lazy){
        int mid = l + ((r - l) >> 1);
        //Left
        seg[2*cur].val += seg[cur].lazy * (mid - l + 1);
        seg[2*cur].lazy += seg[cur].lazy;
        //Right
        seg[2*cur + 1].val += seg[cur].lazy * (r - mid);
        seg[2*cur + 1].lazy += seg[cur].lazy;

        seg[cur].lazy = 0;
    }
}

int query(int cur,int l,int r,int ql,int qr){
    if(ql > r || qr < l) return 0;
    
    if(ql <= l && qr >= r) return seg[cur].val;

    int mid = l + ((r - l) >> 1);
    pushDown(cur,l,r);//更新懒标记

    int lsum = query(cur * 2,l,mid,ql,qr);
    int rsum = query(cur * 2 + 1,mid + 1,r,ql,qr);
    int sum = lsum + rsum;
    return sum;
}

void update(int cur,int l,int r,int ul,int ur,int val){
    if(ul > r || ur < l) return;

    if(ul <= l && ur >= r){
        seg[cur].val += val * (r - l + 1);
        seg[cur].lazy += val;
        return;
    }

    int mid = l + ((r - l) >> 1);
    pushDown(cur,l,r);
    update(cur * 2, l,mid,ul,ur,val);
    update(cur * 2 + 1,mid + 1,r ,ul,ur,val);

    seg[cur].val = seg[cur * 2].val + seg[cur * 2 + 1].val;
}
void solve(){
    cin >> n >> m;
    seg.resize(n * 4 + 5);
    a.resize(n + 5);
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    for(int i = 0; i < m; i++){
        int op;cin >> op;
        if(op == 1){
            int x,y,k;cin >> x >> y >> k;
            update(1,1,n,x,y,k);
        }
        else{
            int x,y;cin >> x >> y;
            cout << query(1,1,n,x,y) << endl;;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}