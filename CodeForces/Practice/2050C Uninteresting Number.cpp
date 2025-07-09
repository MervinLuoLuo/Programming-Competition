/*https://codeforces.com/problemset/problem/2050/C*/
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
    string s;cin >> s;
    int n = s.size();
    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = s[i] - '0';
    int sum = accumulate(a.begin(),a.end(),0LL);
    int cnt2 = 0,cnt3 = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 2) cnt2++;
        if(a[i] == 3) cnt3++;
    }
    for(int i = 0; i < min(10LL, (cnt2 + 1)); i++){
        for(int j = 0; j < min(10LL,cnt3 + 1); j++){
            int cur = sum + 2 * i + j * 6;
            if(cur % 9 == 0) {yes;return;}
        }
    }
    no;
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