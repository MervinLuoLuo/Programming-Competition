#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;

void solve(){
    int n;cin >> n;
    if(n & 1){
        for(int i = 1; i <= n; i++) cout << i << " ";
    }
    else{
        for(int i = 2;i <= n; i += 2) cout << i << " " << i - 1 << " ";
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}