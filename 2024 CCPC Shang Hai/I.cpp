#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn = 1e7;
const int INF = 1e17;
const int mod = 998244353;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n,k;cin>> n >> k;
        priority_queue<int> pq;
        for(int i = 0; i < n; i++){
            int x;cin >> x;
            if(x != 0) pq.push(x);
        }
        if(pq.empty()){cout << 0 << endl;continue;}
        int ans = pq.top();pq.pop();
        while(pq.size() >= k - 1){
            int tmp = k - 1;
            while(tmp--){
                int x = pq.top();
                pq.pop();
                ans = (ans * x )% mod;
            }
        }
        cout << ans % mod << endl;
    }
    return 0;
}