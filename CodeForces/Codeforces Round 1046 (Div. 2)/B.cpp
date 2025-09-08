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
    int n,k;cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        char x;cin >> x;
        a[i] = x - '0';
    }

    //滑动窗口检查长度 k 的连续 1 串 
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += a[i];
        if(i >= k) cnt -= a[i - k];
        if(i >= k - 1 && cnt == k){no; return;}
    }

    int l = 1,r = n;
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        if(a[i] == 1) {ans[i] = l,l++;}
        else{ans[i] = r;r--;}
    }

    yes;
    for(int x : ans) cout << x << " ";
    cout << endl;
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