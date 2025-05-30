#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

bool can(vector<int>& a, int n, int k, int x){
    if(x==0)return 1;
    int s=0, miss=x;
    vector<bool> vis(x,0);
    for (int i=0; i<n; i++){
        int v = a[i];
        if(v < x and !vis[v]){
            vis[v] = 1;
            miss--;
        }
        if(miss==0){
            s++;
            miss = x;
            fill(vis.begin(), vis.end(), 0);
        }
    }
    return s>=k;
}

void solve(){
    int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        vector<bool> freq(n+2, 0);
        for (int i=0; i<n; i++){
            if(a[i] <= n) freq[a[i]] = 1;
        }
        int gm = 0;
        while(gm < (int)freq.size() and freq[gm]) gm++;
        
        int lo = 0, hi = gm;
        while(lo < hi){
            int mid = (lo + hi + 1) / 2;
            if(can(a, n, k, mid))
                lo = mid;
            else
                hi = mid - 1;
        }
        cout << lo << endl;
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