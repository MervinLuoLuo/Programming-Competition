#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
struct Node{
    int val = -1;
    int lazy = 0;
};

int n,k;
vector<PII> a;
vector<Node> seg;

void build(int cur,int l,int r){
    if(l == r){
        seg[cur].val = 0;
        return;
    }

    int mid = l + (r - l) / 2;
    build(cur * 2,l, mid);
    build(cur * 2 + 1,mid + 1, r);
    seg[cur].val = 0;
}

void pushDown(int cur,int l,int r){
    if(seg[cur].lazy != 0){
        int lazy = seg[cur].lazy;
        int mid = l + (r - l) / 2;

        seg[cur * 2].val += lazy;
        seg[cur * 2].lazy += lazy;

        seg[cur * 2 + 1].val += lazy;
        seg[cur * 2 + 1].lazy += lazy;

        seg[cur].lazy = 0;
    }
}

int query(int cur,int l,int r,int ql,int qr){
    if(ql > r || qr < l) return 0;
    if(ql <= l && qr >= r) return seg[cur].val;
    
    int mid = l + (r - l) / 2;
    int L = query(cur * 2,l ,mid, ql,qr);
    int R = query(cur * 2,mid + 1,r,ql,qr);
    return max(L,R);
}

void modify(int cur,int l,int r,int ul,int ur,int val){
    if(ur < l || ul > r) return;
    if(ul <= l && ur >= r){
        seg[cur].val += val;
        seg[cur].lazy += val;
        return;
    }

    int mid = l + (r - l )/ 2;
    pushDown(cur,l,r);
    modify(cur * 2,l,mid,ul,ur,val);
    modify(cur * 2 + 1,mid + 1,r,ul,ur,val);
    seg[cur].val = max(seg[cur * 2].val ,seg[cur * 2 + 1].val);
}

void solve(){
    cin >> n >> k;
    a.clear();a.resize(n + 1);
    seg.clear();seg.resize(4 * n + 5);
    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    build(1,1,n);

    int l = 1,r = 1;
    int ans = r - l + 1;
    while(l <= n && r <= n){
        auto &[L,R] = a[r];
        modify(1,1,n,L,R,1);
        
        int maxx = query(1,1,n,1,n);
        while(maxx > k && l <= r){
            auto &[LL,RR] = a[l];
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
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}