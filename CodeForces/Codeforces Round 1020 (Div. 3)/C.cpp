/*https://codeforces.com/contest/2106/problem/C*/
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
    vector<int> a(n), b(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    //检查合理性
    int cur = -1;
    for(int i = 0; i < n;i++){
        if(b[i] != -1){
            if(cur == -1) cur = b[i] + a[i];
            else {if(b[i] + a[i] != cur){cout << 0 << endl;return;}}
        }
    }
    if(cur == -1){
        sort(a.begin(),a.end());
        int maxx = a[n - 1] - a[0];
        cout << k - (maxx - 1) << endl;
        return;
    }
    for(int i = 0;i  < n;i++){
        if(a[i] > cur or cur - a[i] > k){
            cout << 0 << endl;return;
        }
    }
    cout << 1<< endl;
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