#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int INF = 1e17;
const int maxn = 1e7;
const int mod = 998244353;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n, k;cin >> n >> k;
        priority_queue<int> pq;
        for(int i = 0; i < n; i++){
            int num;cin >> num;
            if(num >= 1)pq.push(num);
        }
        while(pq.size() >= k){
            int prod_k = 1;
            int cnt = 0;
            while(cnt < k){
                cnt++;
                int num = pq.top();pq.pop();
                prod_k = (prod_k * num) % mod;
            }
            pq.push(prod_k);
        }
        if(pq.empty()) cout << 0 << endl;
        else cout << pq.top() % mod << endl;
    }
    return 0;
}