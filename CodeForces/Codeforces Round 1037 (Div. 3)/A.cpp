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
    int x;cin >> x;
    string s = to_string(x);
    int n = s.size();
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        a[i] = s[i] - '0';
    }
    sort(a.begin(),a.end());
    cout << a[0] << endl;
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