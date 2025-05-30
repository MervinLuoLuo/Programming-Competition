/*https://codeforces.com/contest/2078/problem/B*/
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
    int n, k;cin >> n >> k;    
    for(int i = 1; i <= n - 2; i++){
        if(k % 2) cout << n << " ";
        else cout << n-1 << " ";
    }
    cout << n << " " << n - 1 << endl;
    
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