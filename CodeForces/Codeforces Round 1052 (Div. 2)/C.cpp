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
    int n;cin >> n;
    string s;cin >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = i + 1;

    int l = 0;
    while(l < n){
        if(s[l] == '1'){l++;continue;}
        int r = l;
        while(r + 1 < n && s[r + 1]== '0') r++;
        if(r - l + 1 == 1) {no;return;}
        for(int i = l; i < r; i++) a[i] = i + 2;
        a[r] = l + 1;
        l = r + 1; 
    }

    yes;
    for(auto it : a) cout << it << " ";
    cout << endl;
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