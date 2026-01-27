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
    if(n == (1 << __lg(n))){cout << -1 << endl;return;}
    if(n % 2 == 0){
        vector<int> ans = {n};
        for(int i = 2; i <= n - 2; i+= 2){
            ans.push_back(i + 1);
            ans.push_back(i);
        }
        ans.push_back(1);
        int x = n - (1 << __lg(n));
        swap(ans[0],ans[x - 1]);
        for(int x : ans) cout << x << " ";
        cout << endl;
    }
    else{
        cout << n - 1 << " ";
        for(int i = 2; i <= n - 3; i += 2) cout << i + 1 << " " << i << " ";
        cout << n << " " << 1 << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}