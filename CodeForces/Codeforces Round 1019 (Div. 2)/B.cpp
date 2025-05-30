/*https://codeforces.com/contest/2103/problem/B*/
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
    int ans = 0;
    char cur = '0';
    for(int i = 0; i < n; i++){
        if(s[i] != cur) ans++;
        cur = s[i];
    }
    if(ans >= 3) ans -=2;
    else if(ans == 2) ans--;
    cout << ans + n << endl;
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