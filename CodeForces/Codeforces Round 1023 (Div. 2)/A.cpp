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
    bool flag = 0;
    for(int i = 1; i < n; i++){
        if(a[i] != a[i - 1]) {flag = 1;break;}
    }
    if(!flag){no;return;}
    yes;
    int maxx = *max_element(a.begin(),a.end());
    for(int i = 0; i < n; i++){
        if(a[i] == maxx) cout << 1 << " ";
        else cout << 2 << " ";
    }
    cout << endl;
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