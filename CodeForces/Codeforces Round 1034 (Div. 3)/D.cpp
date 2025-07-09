#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Alice" << endl
#define no cout << "Bob" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,k;cin >> n >> k;
    string s;cin >>s;
    int cnt = 0;
    for(int i = 0; i < n; i++) if(s[i] == '1') cnt++;
    if(cnt <= k) {yes;return;}
    int count = 0;
    for(int i = 0;i  < n; i++){
        if(s[i] == '0') count++;
        else count = 0;
        if(count >= k) break;
    }
    if(count >= k || 2 * k <= n ) no;
    else yes;
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