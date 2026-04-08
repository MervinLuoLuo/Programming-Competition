/*https://codeforces.com/contest/2217*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,k;cin >> n >> k;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int sum = accumulate(a.begin(),a.end(),0ll);
    if(sum % 2 == 1) cout << "YES" << endl;
    else{
        if(n * k % 2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}