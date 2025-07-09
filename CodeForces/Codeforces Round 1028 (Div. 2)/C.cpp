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
    int n;cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    if(n == 1){cout << 0 << endl;return;}
    int g = a[0];
    for(int i = 1; i < n; i++) g = __gcd(g,a[i]);

    int cnt = 0;
    for(int x : a){
        if(x == g) cnt++;
    }
    
    if(cnt > 0){cout << n - cnt << endl;return;}

    vector<int> st = a;
    sort(st.begin(),st.end());
    st.erase(unique(st.begin(),st.end()),st.end());
    int m = st.size();
    vector<int> dist(5005,maxn);
    queue<int> q;
    for(int x : st) {
        dist[x] = 0;
        q.push(x);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        int dx = dist[cur];
        if(cur == g) break;

        for(int y : st){
            int w = __gcd(cur,y);
            if(dist[w] > dx + 1){
                dist[w] = dx + 1;
                q.push(w);
            }
        }
    }
    cout << dist[g] + (n - 1) << endl;
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