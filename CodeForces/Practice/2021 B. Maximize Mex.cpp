/*https://codeforces.com/problemset/problem/2021/B*/
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
    int n,x;cin >> n >> x;
    map<int,int> a;
    for(int i = 0; i < n;i++){
        int r;cin >> r;
        a[r]++;
    }
    for(auto it : a){
        if(it.second > 1){
            a[it.first + x] += it.second - 1;
            it.second = 1;
        }
    }
    int i = 0;
    for(; i < 1e9; i++){
        if(a[i] == 0) break;
    }
    cout << i << endl;
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