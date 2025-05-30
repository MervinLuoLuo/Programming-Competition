/*https://www.luogu.com.cn/problem/P1204*/
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
    int n,k;cin >> n >> k;
    vector<int> a(n + 5);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> b;
    for(int i = 2; i <= n; i+=2){
        b.push_back(a[i]);
    }
    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}