#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

struct Node {
    int idx;
    int val;
    bool operator<(const Node &o) const {
        return val < o.val;
    }
};


void solve(){
    int n;cin >> n;
    vector<int> a(n + 2,0);
    for(int i = 1 ; i <= n; i++) cin >> a[i];
    vector<int> L(n + 2),R(n + 2);
    for(int i = 0; i <= n + 1; i++){
        L[i] = i - 1;
        R[i] = i + 1;
    }
    priority_queue<Node> pq;

    auto pu = [&](int i){
        int v = (L[i] >= 1 && R[i] <= n ? max(a[L[i]],a[R[i]]) : 0);
        pq.push({i,v});
    };

    for(int i = 1; i <= n; i++) pu(i);

    int ans = 0, re = 0;
    vector<bool> isr(n + 2, 0);
    while(re < n){
        auto cur = pq.top();pq.pop();
        int idx = cur.idx;
        if(isr[idx]) continue;
        int rv = (L[idx] >= 1 && R[idx] <= n ? max(a[L[idx]],a[R[idx]]) : 0);
        if(rv != cur.val){pu(idx);continue;}

        isr[idx] = 1;
        ans += rv;
        re++;

        int l = L[idx], r = R[idx];
        R[l] = r;L[r] = l;
        if(l >= 1 && l <= n) pu(l);
        if(r >= 1 && r <= n) pu(r);
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