/*https://ac.nowcoder.com/acm/problem/25867*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n),b(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    sort(b.begin(),b.end());
    int sum = accumulate(a.begin(),a.end(),0LL);
    if(b[n - 1] + b[n - 2] >= sum) cout << "YES";
    else cout << "NO";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}