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
    int n, k;cin >> n >> k;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int sum = accumulate(a.begin(),a.end(),0);
    int maxx = *max_element(a.begin(),a.end());
    for(int i = 0; i < n; i++){
        if(a[i] == maxx) {a[i]--;break;}
    }
    maxx = *max_element(a.begin(),a.end());
    int minx = *min_element(a.begin(),a.end());
    cout << (sum & 1 and (maxx - minx) <= k ? "Tom" : "Jerry") << endl;

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