/*https://codeforces.com/problemset/problem/2106/D*/
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
    int n,m;cin >> n >> m;
    vector<int> a(n),b(m),pre(m),suf(m);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    //后缀
    int j = n - 1;
    for(int i = m - 1; i >= 0; i--){
        while(j >= 0 && a[j] < b[i]) j--;
        suf[i] = j--;
    }
    //前缀
    j = 0;
    for(int i = 0; i < m ;i++){
        while(j < n && a[j] < b[i]) j++;
        pre[i] = j++;
    }

    if(pre.back() < n) {cout << 0 << endl;return;}
    int ans = INF;
    for(int i = 0; i < m; i++){
        int cpre = -1;
        if(i != 0) cpre = pre[i - 1];
        int cnext = n;
        if(i + 1 != m) cnext = suf[i + 1];
        if(cpre < cnext) ans = min(ans,b[i]);
    }
    cout << (ans == INF ? -1 : ans) << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    //t = 1;
    while(t--){
       solve();
    }
    return 0;
}