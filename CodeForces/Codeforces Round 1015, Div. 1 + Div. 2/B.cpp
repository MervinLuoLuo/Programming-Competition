/*https://codeforces.com/contest/2084/problem/B*/
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
    for(int i = 0; i < n; i++)cin >> a[i];
    int d = *min_element(a.begin(),a.end());
    int cnt = count(a.begin(),a.end(),d);
    if(cnt == 1){
        int cur = 0;
        bool flag = 0;
        for(int i = 0; i < n; i++){
            if(a[i] != d and a[i] % d == 0){
                cur = (cur == 0 ? a[i] : __gcd(cur, a[i]));
                flag = 1;
            }
        }
        if(!flag or cur != d) {no;return;}
        yes;
    }
    else yes;
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
