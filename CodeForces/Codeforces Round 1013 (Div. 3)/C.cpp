/*https://codeforces.com/contest/2091/problem/C*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "-1" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> ans(n + 5);
    if(n % 2 == 0){no;return;}
    for(int i = 1; i <= n; i++){
        ans[i] = (2 * i - 1) % n;
        if(ans[i] == 0) ans[i] = n;
    }
    for(int i = 1; i <=n;i ++)cout << ans[i] << " ";
    cout << endl;
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