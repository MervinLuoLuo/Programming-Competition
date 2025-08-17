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
    int n = 10;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int good = a[0] + a[4] + a[8];
    int A = a[1] + a[3] + a[5] + a[7];
    int B = a[2];
    int C = a[6] + a[9];

    int sum = A + B + C;
    int l = A, r = A + C;
    int mid = (sum >> 1);
    int best = max(l,min(r,mid));
    int maxp = min(best,sum - best);
    if(sum == 0) maxp = 0;
    
    cout << good + maxp << endl;
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