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
    int l1,b1,l2,b2,l3,b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if(l1 + l2 + l3 == b1 && b1 == b2 && b2 == b3) yes;
    else if(l2 + l3 == l1 && b2 == b3 && b1 + b2 == l1) yes;
    else if(b1 + b2 + b3 == l1 && l1 == l2 && l2 == l3) yes;
    else if(b2 + b3 == b1 && l2 == l3 && l1 + l2 == b1) yes;
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