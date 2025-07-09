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
    int n,j,k;cin >> n >> j >> k;
    j--;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int maxn = *max_element(a.begin(),a.end());
    if(k >= 2) yes;
    else{
        if(a[j] == maxn) yes;
        else no;
    }
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