/*https://codeforces.com/contest/2086/problem/B*/
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
    int n,k,x;cin >> n >> k >> x;
    vector<int> a(n),prefix(n);
    for(int i = 0; i < n; i++){ 
        cin >> a[i];
        prefix[i] = a[i] + (i > 0 ? prefix[i-1] : 0);
    }
    int sum = prefix.back(); 
    vector<int> surfix(n);
    surfix[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--) 
        surfix[i] = max(a[i], a[i] + surfix[i+1]);
    int ans = 0;
    if(sum > 0){
        for(int i = 0; i < n; i++){
            int cur = sum - (i > 0 ? prefix[i-1] : 0);
            if(cur >= x){
                ans += k;
                continue;
            }
            int need = x - cur;
            if(need <= 0){
                ans += k;
                continue;
            }
            int blocks = (need + sum - 1) / sum;
            if(blocks <= k-1) ans += (k - blocks);
        }
    }
    else{
        for(int i = 0; i < n; i++){
            if(surfix[i] >= x) ans += k;
        }
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