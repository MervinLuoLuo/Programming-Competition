/*https://codeforces.com/problemset/problem/2056/B*/
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
    vector<string> s(n);
    for(string &x : s)cin >> x;
    vector<int> ans(n);
    iota(ans.begin(),ans.end(),0);
    sort(ans.begin(),ans.end(),[&](int x,int y){
        if(s[x][y] == '1') return x < y;
        else return x > y;
    });
    for(auto it : ans) cout << it + 1LL << " ";
    cout << endl;
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