#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,m;cin >> n >> m;
    vector<int> a(n + 1),x(m + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> x[i];
    
    priority_queue<int> oq,eq;
    int omax = -INF,emax = -INF;
    bool oflag = 1,eflag = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] >= 0){
            if(i % 2) oq.push(a[i]);
            else eq.push(a[i]);
        }
        if(i & 1) omax = max(omax,a[i]);
        else emax = max(emax,a[i]);
    }

    int ans = accumulate(a.begin(),a.end(), 0ll);
    for(int i = 1; i <= m; i++){
        if(x[i] % 2){
            if(!oq.empty()){
                oflag = 0;
                ans -= oq.top();
                oq.pop();
            }
            if(oflag){
                ans -= omax;
                oflag = 0;
            }
        }
        else{
            if(!eq.empty()){
                eflag = 0;
                ans -= eq.top();
                eq.pop();
            }
            if(eflag){
                ans -= emax;
                eflag = 0;
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}