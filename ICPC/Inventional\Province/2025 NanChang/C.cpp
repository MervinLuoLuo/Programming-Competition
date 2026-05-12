#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
struct Node{
    int val = -1;
    int lazy = 0;
};

int n,k;
vector<Node> seg;
vector<PII> ran;

void build(int cur, int l,int r){
    if(l == r){
        seg[cur].val = 0;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * cur,l,mid);
    build(2 * cur + 1,mid + 1,r);
    seg[cur].val = max(seg[cur * 2].val,seg[cur * 2 + 1].val);
}

void pushDown(int cur){
    if(seg[cur].lazy != 0){
        int tag = seg[cur].lazy;

        seg[cur * 2].val += tag;
        seg[cur * 2].lazy += tag;

        seg[cur * 2 + 1].val += tag;
        seg[cur * 2 + 1].lazy += tag;

        seg[cur].lazy = 0;
    }
}

void modify(int cur,int l,int r, int ul,int ur,int v){
    if(ul > r || ur < l) return;
    if(ul <= l && r <= ur){
        seg[cur].val += v;
        seg[cur].lazy += v;
        return ;
    }

    pushDown(cur);
    int mid = l + (r - l) / 2;
    modify(cur * 2,l,mid ,ul,ur,v);
    modify(cur * 2 + 1,mid + 1,r,ul,ur,v);
    seg[cur].val = max(seg[cur * 2].val,seg[cur * 2 + 1].val);
}

int query(int cur,int l,int r,int ql,int qr){
    if(ql > r || qr < l) return -INF;
    if(ql <= l && qr >= r) return seg[cur].val;
    pushDown(cur);
    int mid = l + (r - l) / 2;
    int L = query(cur * 2,l,mid,ql,qr);
    int R = query(cur * 2 + 1,mid + 1,r,ql,qr);
    return max(L,R);
}

void solve(){
    cin >> n >> k;
    seg.clear();seg.resize(4 * n + 5);
    build(1,1,n);
    ran.clear();ran.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> ran[i].first >> ran[i].second;

    int l = 1,r = 1;
    int ans = r - l + 1;
    while(l <= n && r <= n){
        auto &[L,R] = ran[r];
        modify(1,1,n,L,R,1);
        
        int maxx = query(1,1,n,1,n);
        while(maxx > k && l <= r){
            auto &[LL,RR] = ran[l];
            modify(1,1,n,LL,RR,-1);
            maxx = query(1,1,n,1,n);
            l++;
        }
        
        ans = max(ans,r - l + 1);
        r++;
    }
    
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}

/*
2
3 1
1 2
2 3
3 3
5 2
1 5
1 3
2 4
4 5
1 1

*/