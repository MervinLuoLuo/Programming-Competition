#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<int,int>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n),b(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    int maxx = 0,minx = 0;
    for(int i = 0; i < n; i++){
        int nwmaxx = max(maxx - a[i],b[i] - minx);
        int nwminx = min(minx - a[i],b[i] - maxx);
        maxx = nwmaxx;minx = nwminx;
    }

    cout << maxx << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}