#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;
constexpr int N = 2e5 + 10;

struct Node{
    int l,r;
    int g;// gcd
};
vector<Node> tr(N << 2);
vector<int> a;
vector<int> vec[N + 10];//因子个数

void init(){
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j += i){
            vec[j].push_back(i);
        }
    }
}
void build(int cur,int l,int r){
    tr[cur] = {l,r,0};
    if(l == r) return;

    int mid = l + r >> 1;
    build(cur << 1,l,mid);
    build(cur << 1 | 1,mid + 1, r);
}

void pushup(int cur){
    tr[cur].g = gcd(tr[cur << 1].g,tr[cur << 1 | 1].g);
}//更新

void modify(int cur,int tar,int val){
    if(tr[cur].l == tr[cur].r){
        tr[cur].g = val; 
        return;
    }

    int mid = tr[cur].l + tr[cur].r >> 1;
    if(tar <= mid) modify(cur << 1,tar,val);
    else modify(cur << 1 | 1,tar,val);
    pushup(cur);
}

void solve(){
    int n,q;cin >> n >> q;
    a.assign(n + 1,0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    
    //q = 0
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i + 1]) modify(1,i,i);
    }
    if(tr[1].g){
        cout << vec[tr[1].g].size() << endl;
    }
    else cout << n << endl;

    while(q--){
        int x,y;cin >> x >> y;
        a[x] = y;

        //左边
        if(x > 1 && a[x - 1] > a[x]) modify(1,x - 1,x - 1);
        else if(x > 1) modify(1,x - 1, 0);
        //右边
        if(x < n && a[x] > a[x + 1]) modify(1,x,x);
        else if(x < n) modify(1,x,0);
        if(tr[1].g) cout << vec[tr[1].g].size() << endl;
        else cout << n << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    init();
    while(t--){
        solve();
    }
    return 0;
}