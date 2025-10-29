#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int cur = 0;
    cin >> cur;
    bool flag = 1;
    for(int i = 2; i <= 4; i++){
        int x;cin >> x;
        if(x != cur) flag = 0;
    }
    if(!flag) no;
    else yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}