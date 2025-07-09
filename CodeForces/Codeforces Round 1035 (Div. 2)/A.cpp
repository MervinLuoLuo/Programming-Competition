#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int a, b, x, y;cin >> a >> b >> x >> y;
    // unordered_map<int, int> dist;
    // deque<int> dq;
    // dist[a] = 0;
    // dq.push_front(a);
    // while (!dq.empty()) {
    //     int u = dq.front();
    //     dq.pop_front();
    //     if (u == b) {cout << dist[u] << endl;return;}
    //     int v1 = u + 1;
    //     if (v1 <= 2 * b && (!dist.count(v1) || dist[v1] > dist[u] + x)) {
    //         dist[v1] = dist[u] + x;
    //         dq.push_back(v1); 
    //     }

    //     int v2 = u ^ 1;
    //     if (v2 <= 2 * b && (!dist.count(v2) || dist[v2] > dist[u] + y)) {
    //         dist[v2] = dist[u] + y;
    //         dq.push_front(v2); 
    //     }
    // }

    // cout << -1 << endl;
    if(a > b){
        if(a - 1 == b && a & 1) cout << y << endl;
        else cout << -1 << endl; 
    }
    else{
        if(x < y) cout << (b - a) * x << endl;
        else {
            if(a & 1) cout << (int)ceil((b - a) / 2.0) * x + (int)floor((b - a) / 2.0) * y << endl;
            else  cout << (int)ceil((b - a) / 2.0) * y + (int)floor((b - a) / 2.0) * x << endl;
        }
    }
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