/*https://codeforces.com/contest/2065/problem/C1*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
typedef long long ll;

void solve(){
    int n,m;cin >> n >> m;
    vector<int> a(n + 5);
    for(int i = 0; i < n; i++) cin >> a[i];
    int b;cin >> b;
    bool flag = 1;
    a[0] = min(a[0],b - a[0]);
    for(int i = 1; i < n; i++){
        if(a[i] >= a[i - 1] and b - a[i] >= a[i - 1]) a[i] = min(a[i], b - a[i]);
        else if(a[i] < a[i - 1] and b - a[i] >= a[i  - 1]) a[i] = b - a[i];
        if(a[i] < a[i - 1]){
            flag = 0;
            break;
        }
    }
    //for(auto it : a) cout << it << ' ';
    if(flag) yes;
    else no;
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