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
    string ans = "";
    int l = 0, r = n - 1;
    for(int i = 1; i <= n; i++){
        if(i & 1){
            if(a[l] <= a[r]) {ans +="L";l++;}
            else {ans +="R";r--;}
        }
        else{
            if(a[l] <= a[r]){ans += "R";r--;}
            else {ans +='L';l++;}
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