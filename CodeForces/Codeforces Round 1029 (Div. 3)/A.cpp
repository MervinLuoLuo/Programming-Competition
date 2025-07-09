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
    int n,x;cin >> n >> x;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    int posl = -1,posr = -1;
    for(int i = 0;i < n; i++){
        if(a[i] == 1){
            if(posl == -1) posl = i;
            posr = i;
        }
    }
    if(posr - posl  + 1 <= x) yes;
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