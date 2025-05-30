/*https://codeforces.com/contest/2085/problem/D*/
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
    int n,k;cin >> n >> k;
    priority_queue<int> pq;
    vector<int> a(n + 5);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int r = (n - k) % (k + 1);
    int ans = 0;
    for(int i = 1; i <= r; i++) pq.push(a[i]);
    if(!pq.empty()){
        ans += pq.top();
        pq.pop();

    }
    int cnt = 0;
    for(int i = r + 1; i <= n; i++){
        cnt++;
        pq.push(a[i]);
        if(cnt == (k + 1)){
            ans += pq.top();
            pq.pop();
            cnt = 0;
        }
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}