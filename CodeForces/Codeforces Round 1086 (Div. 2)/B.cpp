#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,k,p,m;cin >> n >> k >> p >> m;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n ;i++) cin >> a[i];
    priority_queue<int,vector<int>,greater<int>> pq,q;
    for(int i = 1; i <= k - 1; i ++) pq.push(a[i]);
    for(int i = k; i <= p - 1; i++){
        pq.push(a[i]);
        m -= pq.top();
        pq.pop();
    }
    m -= a[p];
    if(m < 0) {
        cout << 0 << endl;
        return;
    }

    int B = a[p];
    for(int i = 1; i <= n; i++){
        if(i == p) continue;
        q.push(a[i]);
    }

    for(int i = 1; i <= n - k; i++){
        B += q.top();
        q.pop();
    }
    cout << 1 + m / B << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}