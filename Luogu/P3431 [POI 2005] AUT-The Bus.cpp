/*https://www.luogu.com.cn/problem/P3431*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int n,m,k;
vector<int> yy;
struct Node{
    int x,y,v;
};
vector<Node> val;
vector<int> seg;

void modify(int cur,int l,int r,int pos,int val){
    if(l == r){
        seg[cur] = val;
        return;
    }

    int mid = l + (r - l) / 2;
    if(pos <= mid) modify(2 * cur, l, mid,pos,val);
    else modify(2 * cur + 1,mid + 1,r,pos,val);

    seg[cur] = max(seg[2 * cur],seg[2 * cur + 1]);
}

int query(int cur,int l,int r,int ql,int qr){
    if(qr < l || ql > r) return 0;
    if(ql <= l && qr >= r) return seg[cur];

    int mid = l + (r - l) / 2;
    int L = query(2 * cur,l,mid,ql,qr);
    int R = query(2 * cur + 1,mid + 1,r,ql,qr);
    int res = max(L,R);
    return res;
}

void solve(){
    cin >> n >> m >> k;
    val.assign(k + 1,{0,0,0});
    for(int i = 1; i <= k; i++){
        int x,y,v;cin >> x >> y >> v;
        val[i].x = x;val[i].y = y;val[i].v = v;
        yy.push_back(y);
    }

    sort(yy.begin(),yy.end());
    yy.erase(unique(yy.begin(),yy.end()),yy.end());

    sort(val.begin() + 1,val.end(),[](Node a,Node b){
        if(a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });

    seg.assign(yy.size() * 4 + 1,0);

    int ans = 0;
    for(int i = 1;i <= k; i++){
        int dy = lower_bound(yy.begin(),yy.end(),val[i].y) - yy.begin() + 1;
        int f = query(1,1,yy.size(),1,dy) + val[i].v;
        modify(1,1,yy.size(),dy,f);
        ans = max(ans,f);
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}