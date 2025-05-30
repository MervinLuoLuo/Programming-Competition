#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,k;cin >> n >> k;
    string s;cin >> s;
    int cnt1= 0, cnt0 = 0;
    for(int i = 0;i < n; i++){
        if(s[i] == '1') cnt1++;
        else cnt0++;
    }
    int bneed = (n >> 1) - k;
    if(cnt0 < bneed || cnt1 < bneed){no;return;}
    int res1 = (cnt1 - bneed) >> 1, res0 = (cnt0 - bneed) >> 1;
    int sum = res1 + res0;
    if(sum >= k) yes;
    else no;

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