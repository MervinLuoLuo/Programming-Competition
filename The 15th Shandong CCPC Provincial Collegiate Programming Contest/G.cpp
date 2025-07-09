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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        int t,w;cin >> w >> t;
        a[i] = t + k - w;
    }
    sort(a.begin(),a.end());
    for(int i = 1; i< n; i++){
        a[i] = max(a[i],a[i - 1] + 1);
    }
    cout << *max_element(a.begin(),a.end()) << endl;
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