#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int gpos(int x){
    if(x == 0) return 0;
    int cnt = 0;
    while(x){
        if((x & 1) == 0) return cnt;
        x >>= 1;cnt++;
    }
    return cnt;
}

int popcount(int x){
    int res = 0;
    while(x){
        if(x & 1) res++;
        x >>= 1;
    }
    return res;
}

struct Node{
    int x;
    friend bool operator<(Node a,Node b){
        return gpos(a.x) > gpos(b.x);
    }
};

void solve(){
    int n,k;cin >> n >> k;
    priority_queue<Node> pq;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        pq.push({x});
    }

    while(true){
        int cur = pq.top().x, cnt = gpos(cur);
        if ((1LL << cnt) <= k) {
            cur += (1LL << cnt);
            k -= (1LL << cnt);
            pq.pop(), pq.push({cur});
        } 
        else break;
    }
    int res = 0;
    while (!pq.empty()) {
        res += popcount(pq.top().x);
        pq.pop();
    }
    cout << res << endl;
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