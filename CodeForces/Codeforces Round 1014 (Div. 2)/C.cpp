/*https://codeforces.com/contest/2092/problem/C*/
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
    int sum = 0 , cnt = 0;
    for(int i = 0;i < n; i++){
        cin >> a[i];
        sum += a[i];
        cnt += a[i] & 1;
    }
    if(cnt == 0 or cnt == n){cout << *max_element(a.begin(),a.end()) << endl;return;}
    cout << sum - cnt + 1 << endl;
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