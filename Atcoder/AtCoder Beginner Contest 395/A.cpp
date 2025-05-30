/*https://atcoder.jp/contests/abc395*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    bool flag = 1;
    for(int i = 0; i < n; i++){cin >> a[i];}
    for(int i = 1; i < n; i++){
        if(a[i] <= a[i - 1]){flag = 0;break;}
    }
    if(flag) yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}