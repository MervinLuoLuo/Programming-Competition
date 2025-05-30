/*https://codeforces.com/contest/2103/problem/A*/
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
    vector<int> a(n),b;
    for(int &x : a) cin >> x;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int add = 1;
        for(int j = 0; j < i; j++){
            if(a[i] == a[j]) {add = 0;break;}
        }
        ans += add;
    }
    cout << ans << endl;
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