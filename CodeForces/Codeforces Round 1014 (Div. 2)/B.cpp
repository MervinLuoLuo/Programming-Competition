/*https://codeforces.com/contests/2092/problem/B*/
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
    int n;cin >> n;
    string a,b;cin >> a >> b;
    int cnt[2] {};
    for(int i = 0; i < n; i++){
        if(a[i] == '0') cnt[i & 1]++;
        if(b[i] == '0') cnt[(i + 1) & 1]++;
    }
    if(cnt[0] >= (n + 1) / 2 and cnt[1] >= n / 2 ) yes;
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