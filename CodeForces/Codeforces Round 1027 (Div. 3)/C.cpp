#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e6;//注意这里开 1e6 已经接近极限了,再往大的开可能会爆

vector<int> tree, idx;

void build(int x, int l,int r,int u,int v){
    idx.push_back(x);
    if(l == r){tree[x] = max(tree[x],v);return;}

    int mid = (l + ((r - l) >> 1));
    if(u <= mid) build(2 * x ,l,mid,u,v);
    else build(2*x+1,mid+ 1,r,u,v);
    tree[x] = max(tree[x* 2],tree[x * 2 + 1]);
}

int query(int x,int l, int r,int ql ,int qr){
    if(ql > qr) return 0;
    if(ql <= l && qr >= r) return tree[x];
    int mid = l + ((r - l) >> 1);
    int res = 0;
    if(ql <= mid) res = max(res,query(2*x,l,mid,ql,qr));
    if(qr > mid) res = max(res,query(x*2+1,mid+1,r,ql,qr));
    return res;
}

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    tree.resize(4 * maxn + 5,0);
    for(int &x : a) cin >> x;
    for (int i : idx) {
        if (i < tree.size()) tree[i] = 0;
    }
    idx.clear();
    //经典初始化

    int ans = 0;
    for(int i = 0;i < n; i++){
        int x = a[i], dp = 1;
        if(x - 2 >= 1) dp = max(dp,query(1,1,maxn,1,x - 2) + 1);//这里记得要加上自己成的一段 +1
        int l = max(1LL, x - 1), r = x;
        if(l <= r) dp = max(dp,query(1,1,maxn,l,r));
        build(1,1,maxn,x,dp);//更新
        ans = max(ans,dp);
    }
    cout << ans << endl;
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