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
    string s;cin >> s;
    int cnt = 0, n = s.size();
    for(int i = 0; i < n - 1; i++){
        if(s[i] == '(') cnt++;
        else cnt--;
        if(cnt == 0){yes;return;}
    }
    no;
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