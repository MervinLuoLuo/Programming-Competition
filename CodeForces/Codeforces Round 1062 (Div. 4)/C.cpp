#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    bool flag1 = 0,flag2 = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] & 1) flag1 = 1;
        else flag2 = 1;
    }
    if(flag1 && flag2){
        sort(a.begin(),a.end());
    }
    for(auto it : a) cout << it << " ";
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}