#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

bool cmp(pii &a,pii &b){
    return a.second < b.second;
}

void solve(){
    int n,s;cin >> n >> s;
    vector<pii> a(n);
    vector<int> train(1e6+5,0);
    int cur = 0, sum = 0, ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        train[a[i].second] += a[i].first;
        cur += a[i].first;
        sum += a[i].first * a[i].second;
    }
    for(int i = 1; i <= 1e6; i++){
        if(cur < s) break;
        ans += s;
        sum -= cur;
        cur -= train[i];
    }
    cout << ans + sum << endl;
    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}