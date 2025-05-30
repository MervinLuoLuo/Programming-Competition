/*https://codeforces.com/contest/2106/problem/A*/
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
    string s;cin >> s;
    int cnt_1 = 0;
    for(int i = 0;  i<n; i++){
        if(s[i] == '1')  cnt_1++;
    }
    int cnt_0 = n - cnt_1;
    int ans = cnt_0 * (cnt_1 + 1) + (cnt_1 - 1) * cnt_1;
    cout << ans << endl;
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