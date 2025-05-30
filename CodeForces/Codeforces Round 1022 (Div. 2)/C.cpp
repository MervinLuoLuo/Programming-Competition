/*https://codeforces.com/contest/2108/problem/C*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

bool cmp(const pii &a,const pii &b){
    return a.first < b.first;
}

void solve(){
    int n;cin >> n;
    vector<int> tmp(n);
    vector<pii> a;
    for(int &x : tmp) cin >> x;
    a.push_back({tmp[0],0});
    for(int i = 1; i < n; i++){
        if(tmp[i] == a.back().first) continue;
        a.push_back({tmp[i],a.back().second + 1});
    }
    n = a.size();
    stable_sort(a.begin(),a.end(),cmp);
    // for(auto it : a) cout << it.first << " " << it.second << endl;
    vector<bool> vis(n,0);
    int cnt = 1;
    vis[a[n - 1].second] = 1;
    for(int i = n - 2; i >= 0; i--){
        int cur = a[i].second;
        if(cur - 1 < 0){
            if(!vis[cur + 1]) cnt++;
        }
        else if(cur + 1 >= n){
            if(!vis[cur - 1]) cnt++;
        }
        else {
            if(!vis[cur - 1] and !vis[cur + 1]) cnt++;
        }
        vis[cur] = 1;
        //cout << cnt << " ";
    }
    cout << cnt << endl;
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