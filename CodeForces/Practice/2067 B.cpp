/*https://codeforces.com/problemset/problem/2067/B*/
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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(),a.end());
    for(int i = 0; i < n; i += 2){
        if(a[i] != a[i + 1]){no;return;}
        for(int j = i + 2; j < n; j++){
            if(a[i] == a[j]) a[j] = a[i] + 1;
        }
    }
    yes;
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